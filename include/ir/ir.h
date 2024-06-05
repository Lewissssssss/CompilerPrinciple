#include <iostream>
#include <stack>
#include <ast/ast.h>
#include <cassert>
#include <cstdarg>
#include <stdarg.h>
#include <assert.h>
#include <unordered_map>
// #define BasicBlock int

// typedef struct
// {
//     std::vector<std::vector<Instruction>>::iterator iter_to_BBs;
//     int current_bb;
// } BasicBlock;

typedef struct{
    std::vector<Instruction> inst_list;
    std::string name;
} BasicBlock;

typedef std::vector<BasicBlock> BBs;
int bb_num = 0;


enum Expr_Stmt_type{
    INT_et,
    ID_et,
    BinOp_et,
    Unary_ID_et,
    Unary_ARRAY_et,
    Unary_BinOp_et,
    Call_et,
    ARRAY_et,
    FucDef_est,
    VarDecl_st,
    VarDeclArray_st,
    Expr_st,
    Assign_st,
    If_st,
    IfElse_st,
    While_st,
    Return_st,
    useless_est,
};


// std::vector<std::vector<std::string>> BBs; // GLOBAL, for basic blocks.

typedef std::variant<
        //string,
        int ,
        std::vector<int> ,
        std::vector<std::vector<int>> ,
        std::vector<std::vector<std::vector<int>>> ,
        std::vector<std::vector<std::vector<std::vector<int>>>> ,
        std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>> 
    > value;
// union value {
//     int integer;
//     std::vector<int> array;
//     std::vector<std::vector<int>> list_2;
//     std::vector<std::vector<std::vector<int>>> list_3;
//     std::vector<std::vector<std::vector<std::vector<int>>>> list_4;
//     std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>> list_5;

// };



struct Var_Type {
    Type type;
    value val;
    string tmp_var_name;//类似%1、、、
    // Adding constructors to handle deep copy
    Var_Type() {}
    Var_Type(const Var_Type &v) {
        type = v.type;
        val = v.val;
        tmp_var_name = v.tmp_var_name;
    }

    Var_Type& operator=(const Var_Type& v) {
        if (this != &v) {
            type = v.type;
            val = v.val;
            tmp_var_name = v.tmp_var_name;
        }
        return *this;
    }
};

struct Func_Type {
    Type return_type;
    value return_val;
    std::vector<Type> args;
    int arg_num;

    
    // Adding constructors to handle deep copy
    Func_Type() {}
    Func_Type(const Func_Type &f) {
        return_type = f.return_type;
        return_val = f.return_val;
        args = f.args;
        arg_num = f.arg_num;
    }

    Func_Type& operator=(const Func_Type& f) {
        if (this != &f) {
            return_type = f.return_type;
            return_val = f.return_val;
            args = f.args;
            arg_num = f.arg_num;
        }
        return *this;
    }
};

// union ir_Type{
//     Var_Type var_type;
//     Func_Type func_type;

// };

// struct Func_BasicBlocks{
//     std::vector<std::vector<Instruction>> BBs; // LOCAL, for func's basic blocks.
//     string Func_name;
// };
// Func_BasicBlocks Func_BB_map;

// unordered_map<string, std::vector<std::vector<Instruction>>> Func_BB_map;// GLOBAL, for func's basic blocks.
unordered_map<string, std::vector<BBs>> Func_BB_map;// LOCAL, for func's basic blocks.
string cur_Func;

typedef std::variant<Var_Type, Func_Type, std::unordered_map<std::string, Var_Type>::iterator> ir_Type;//iterator to handel LVal


class Field_Sym{
private:
    //std::vector<std::pair<std::string, Value>> sym_list;
    std::unordered_map<std::string, Var_Type> Var_sym_tbl;
    std::unordered_map<std::string, Func_Type> Func_sym_tbl;
public:
    Field_Sym()=default;
    Field_Sym(const Field_Sym& f){
        Var_sym_tbl=f.Var_sym_tbl;// deep copy
        Func_sym_tbl=f.Func_sym_tbl;
    }
    void add_symbol(std::string Identifier, Var_Type value){
        
        Var_sym_tbl.insert_or_assign(Identifier, value);
    }//Add Varsymbol to current field symtbl
    void add_symbol(std::string Identifier, Func_Type value){
        
        Func_sym_tbl.insert_or_assign(Identifier, value);
    }//Add Funcsymbol to current field symtbl


    Var_Type& lookup_var(std::string Identifier){
        auto iter1=Var_sym_tbl.find(Identifier);
        if(iter1!=Var_sym_tbl.end())
            return iter1->second;
        else std::cout<<'Error in lookup_var!'<<std::endl;
    }
    Func_Type& lookup_func(std::string Identifier){
        auto iter2=Func_sym_tbl.find(Identifier);
        if(iter2!=Func_sym_tbl.end())
            return iter2->second;
        else std::cout<<'Error in lookup_func!'<<std::endl;
    }
    std::unordered_map<std::string, Var_Type>::iterator get_Lval(std::string identifier){
        auto iter = Var_sym_tbl.find(identifier);
        return iter;
    }

};


class Symbol_Tabel{
private:
    //std::unordered_map<std::string, std::vector<Value>> Hash;//To handle same name var's situation, newest is put to use
    std::stack<Field_Sym> Stack;
public:
    Symbol_Tabel()=default;
    Var_Type& lookup_var(std::string Identifier){
        auto& current_sym_tbl= Stack.top();
        return current_sym_tbl.lookup_var(Identifier);
    }
    Func_Type& lookup_func(std::string Identifier){
        auto& current_sym_tbl= Stack.top();
        return current_sym_tbl.lookup_func(Identifier);
    }
    void add_symbol(std::string Identifier, Var_Type n){
        auto& current_sym_tbl= Stack.top();
        current_sym_tbl.add_symbol(Identifier,n);
    }
    void add_symbol(std::string Identifier, Func_Type n){
        auto& current_sym_tbl= Stack.top();
        current_sym_tbl.add_symbol(Identifier,n);
    }
    std::unordered_map<std::string, Var_Type>::iterator get_Lval(std::string identifier){
        auto& current_sym_tbl= Stack.top();
        return current_sym_tbl.get_Lval(identifier);
    }
    Field_Sym& get_current_symbol_tbl(){
        return Stack.top();
    }


    //TBD  push stack and pop stack
};
Symbol_Tabel SYM_TBL;
//std::stack<std::stack<int>> field_stack;
bool canConvertToInt(const std::string& str);
ir_Type translate_expr(Node expr,Symbol_Tabel symbol_table,BasicBlock current_bb);
Expr_Stmt_type get_exprTpye_from_node(Node *node);

BasicBlock translate_stmt(Node stmt,Symbol_Tabel symbol_table,BasicBlock current_bb);



enum OperandType {
    OPD_CONSTANT,
    OPD_VARIABLE,
    OPD_ARGS
};

class Operand {
public:
    Operand(OperandType type, const std::string& value)
        : type_(type), opd_type_(value) {}

    Operand(OperandType type, const value& value)
        : type_(type), opd_type_(value) {}

    Operand(OperandType type, const std::vector<Var_Type>& value)
        : type_(type), opd_type_(value) {}
    Operand(){}
    OperandType getType() const {
        return type_;
    }

    std::variant<std::string, value, std::vector<Var_Type>> getValue() const { return opd_type_; }

public:
    OperandType type_;
    std::variant<std::string, value, std::vector<Var_Type>> opd_type_;
};

enum inst_IR_type{
        /*********** binary operation, 0~12 ***********/
        /******* arithmetic operation, 0~4 *******/
        IR_ADD,
        IR_SUB, // sub & minus
        IR_MUL,
        IR_DIV,
        IR_MOD,
        /******* arithmetic operation, 0~4 *******/
        /******* relational operation, 5~13 *******/
        IR_AND,
        IR_OR,
        IR_XOR,
        IR_GT,
        IR_LT,
        IR_GE,
        IR_LE,
        IR_EQ,
        IR_NE,
        /******* relational operation, 5~13 *******/
        /*********** binary operation, 0~13 ***********/
        
        // memory related, 14~17
        IR_LOAD,
        IR_STORE,
        IR_ALLOCATION,
        IR_OFFSET,

        // jump related, 18~21
        IR_RETURN,
        IR_BRANCH,
        IR_JUMP,
        IR_PANIC, // continue, break...
        
        // function, 22~23
        IR_FUNCDEF,
        IR_CALL,
        
        // label, 24
        IR_LABEL,
    };

class Instruction {
public:
struct inst_binary {
        Operand res, opd1, opd2;
        inst_binary() = default;
        inst_binary(Operand res, Operand opd1, Operand opd2) : res(res), opd1(opd1), opd2(opd2) {}
    };

    struct inst_allocation {
        Operand res, ElementNum;
        inst_allocation() = default;
        inst_allocation(Operand res, Operand ElementNum) : res(res), ElementNum(ElementNum) {}
    };

    struct inst_store {
        Operand res, opd1, opd2;
        inst_store() = default;
        inst_store(Operand res, Operand opd1, Operand opd2) : res(res), opd1(opd1), opd2(opd2) {}
    };

    struct inst_load {
        Operand target, source;
        inst_load() = default;
        inst_load(Operand target, Operand source) : target(target), source(source) {}
    };

    struct inst_offset {
        Operand left, right;
        inst_offset() = default;
        inst_offset(Operand left, Operand right) : left(left), right(right) {}
    };

    struct inst_return {
        Operand res;
        inst_return() = default;
        inst_return(Operand res) : res(res) {}
    };

    struct inst_jump {
        Operand dest;
        inst_jump() = default;
        inst_jump(Operand dest) : dest(dest) {}
    };

    struct inst_branch {
        Operand cond, True_label, False_label;
        inst_branch() = default;
        inst_branch(Operand cond, Operand True_label, Operand False_label) : cond(cond), True_label(True_label), False_label(False_label) {}
    };

    struct inst_panic {
        Operand cond, True_label, False_label;
        inst_panic() = default;
        inst_panic(Operand cond, Operand True_label, Operand False_label) : cond(cond), True_label(True_label), False_label(False_label) {}
    };

    struct inst_funcdef {
        Operand f_name, arg_types, return_type;
        inst_funcdef() = default;
        inst_funcdef(Operand f_name, Operand arg_types, Operand return_type) : f_name(f_name), arg_types(arg_types), return_type(return_type) {}
    };
    struct inst_call {
        Operand res, func, args;
        inst_call() = default;
        inst_call(Operand res, Operand func, Operand args) : res(res), func(func), args(args) {}
    };

    struct inst_label {
        Operand label;
        inst_label() = default;
        inst_label(Operand label) : label(label) {}
    };

    typedef std::variant<inst_binary, inst_allocation, inst_store, inst_load,
                         inst_offset, inst_return, inst_jump, inst_branch,
                         inst_panic, inst_funcdef, inst_call, inst_label> inst_type;

    Instruction(inst_IR_type type, inst_type inst) : type(type), inst(inst) {}

    Instruction(inst_IR_type type, Operand res, Operand opd1, Operand opd2) : type(type) {
        if (type == IR_ADD || type == IR_SUB ||
            type == IR_MUL || type == IR_DIV ||
            type == IR_MOD || type == IR_AND ||
            type == IR_OR || type == IR_XOR ||
            type == IR_GT || type == IR_LT ||
            type == IR_GE || type == IR_LE ||
            type == IR_EQ || type == IR_NE) {
            inst = inst_binary{res, opd1, opd2};
        }
        else if (type == IR_STORE) {
            inst = inst_store{res, opd1, opd2};
        }
        else if (type == IR_BRANCH) {
            inst = inst_branch{res, opd1, opd2};
        }
        else if (type == IR_PANIC) {
            inst = inst_panic{res, opd1, opd2};
        }
        else if (type == IR_FUNCDEF) {
            inst = inst_funcdef{res, opd1, opd2};
        }
        else if (type == IR_CALL) {
            inst = inst_call{res, opd1, opd2};
        }
        assert(false);
    }
    Instruction(inst_IR_type type, Operand opd1, Operand opd2) : type(type) {
        if (type == IR_LOAD) {
            inst = inst_load{opd1, opd2};
        }
        
        else if (type == IR_ALLOCATION) {
            inst = inst_allocation{opd1, opd2};
        }
        else if (type == IR_OFFSET) {
            inst = inst_offset{opd1, opd2};
        }
        assert(false);

    }
    Instruction(inst_IR_type type, Operand res) {
        if (type == IR_RETURN) {
            inst = inst_return{res};
        }
        else if (type == IR_JUMP) {
            inst = inst_jump{res};
        }
        else if (type == IR_LABEL) {
            inst = inst_label{res};
        }
        assert(false);

    }
    inst_IR_type type;
    inst_type inst;
};