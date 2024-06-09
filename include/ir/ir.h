#ifndef IR_H
#define IR_H
#include <iostream>
#include <stack>
#include <ast/ast.h>
#include <cassert>
#include <cstdarg>
#include <unordered_map>
#include <variant>
#include <vector>
#include <regex>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;


enum Expr_Stmt_type {
    // exp : 0~7
    INT_et,
    ID_et,
    BinOp_et,
    Unary_ID_et,
    Unary_ARRAY_et,
    Unary_BinOp_et,
    Call_et,
    ARRAY_et,
    // stmt : 8~16
    FucDef_est,
    VarDecl_st,
    VarDeclArray_st,
    Expr_st,
    Assign_st,
    If_st,
    IfElse_st,
    While_st,
    Return_st,
    Block_st,
    useless_est,
};

typedef std::variant<
        int,
        std::vector<int>,
        std::vector<std::vector<int>>,
        std::vector<std::vector<std::vector<int>>>,
        std::vector<std::vector<std::vector<std::vector<int>>>>,
        std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>
    > value;

struct Var_Type {
    bool is_GLOBAL = false;//defualt not a global, only global sets this filed
    Type type;
    value val;
    std::string tmp_var_name; // 类似%1
    Var_Type() {}
    Var_Type(const Var_Type &v) : type(v.type), val(v.val), tmp_var_name(v.tmp_var_name),is_GLOBAL(v.is_GLOBAL) {}
    Var_Type& operator=(const Var_Type& v) {
        if (this != &v) {
            type = v.type;
            val = v.val;
            tmp_var_name = v.tmp_var_name;
            is_GLOBAL = v.is_GLOBAL;
        }
        return *this;
    }
};

struct Func_Type {
    Type return_type;
    value return_val;
    std::vector<Type> args;
    std::vector<std::string> tmp_arg_name;
    int arg_num;
    Func_Type() {}
    Func_Type(const Func_Type &f) {
        return_type = f.return_type;
        return_val = f.return_val;
        args = f.args;
        tmp_arg_name = f.tmp_arg_name;
        arg_num = f.arg_num;
    }

    Func_Type& operator=(const Func_Type& f) {
        if (this != &f) {
            return_type = f.return_type;
            return_val = f.return_val;
            args = f.args;
            tmp_arg_name = f.tmp_arg_name;
            arg_num = f.arg_num;
        }
        return *this;
    }
};



typedef std::variant<Var_Type, Func_Type, std::unordered_map<std::string, Var_Type>::iterator> ir_Type; // iterator to handle LVal

class Field_Sym {
// private:
    
public:
    std::unordered_map<std::string, Var_Type> Var_sym_tbl;
    std::unordered_map<std::string, Func_Type> Func_sym_tbl;
    Field_Sym() = default;
    Field_Sym(const Field_Sym& f) : Var_sym_tbl(f.Var_sym_tbl), Func_sym_tbl(f.Func_sym_tbl) {}
    void add_symbol(std::string Identifier, Var_Type& value) {
        auto save = new Var_Type(value);
        Var_sym_tbl.insert_or_assign(Identifier, *save);
    }
    void add_symbol(std::string Identifier, Func_Type& value) {
        auto save = new Func_Type(value);
                // cout << "    void add_symbol(const std::string& Identifier, Func_Type n)3" << endl;

        Func_sym_tbl.insert_or_assign(Identifier, *save);
                // cout << "    void add_symbol(const std::string& Identifier, Func_Type n)4" << endl;

    }
    Var_Type& lookup_var(const std::string& Identifier) {
        auto iter1 = Var_sym_tbl.find(Identifier);
        if (iter1 != Var_sym_tbl.end())
            return iter1->second;
        else {
            std::cout << "Error in lookup_var! var_name: " << Identifier<<std::endl;
            //assert(false);
            Var_Type v;
            v.type = VOID_TY;
            v.tmp_var_name = "NOT_FOUND";
            return v;
            // assert(false);
        }
    }
    Func_Type& lookup_func(const std::string& Identifier) {
        auto iter2 = Func_sym_tbl.find(Identifier);
        if (iter2 != Func_sym_tbl.end())
            return iter2->second;
        else{
            std::cout << "Error in lookup_func!" << std::endl;
            Func_Type v;
            v.return_type = VOID_TY;
            v.tmp_arg_name = {"NOT_FOUND"};
            v.arg_num = 0;
            return v;
        }
        assert(false);

    }
    std::unordered_map<std::string, Var_Type>::iterator get_Lval(const std::string& identifier) {
        return Var_sym_tbl.find(identifier);
    }
    int get_current_tbl_size(){return Var_sym_tbl.size();}
};

class Symbol_Table {
public:
    std::stack<Field_Sym> Stack;


    Symbol_Table() {
        Stack = stack<Field_Sym>{};
    }
    Var_Type& lookup_var(const std::string& Identifier) {
        return Stack.top().lookup_var(Identifier);
    }
    Func_Type& lookup_func(const std::string& Identifier) {
        return Stack.top().lookup_func(Identifier);
    }
    void add_symbol(const std::string& Identifier, Var_Type& n) {
        auto save = new Var_Type(n);
        //cout<<"QAQAQAQAQ "<<save->tmp_var_name<<save->is_GLOBAL<<endl;
        Stack.top().add_symbol(Identifier, *save);
    }
    void add_symbol(const std::string& Identifier, Func_Type& n) {
        auto save = new Func_Type(n);
        //cout << "    void add_symbol(const std::string& Identifier, Func_Type n)" << endl;

        Stack.top().add_symbol(Identifier, *save);
        //cout << "    void add_symbol(const std::string& Identifier, Func_Type n)2" << endl;

    }
    std::unordered_map<std::string, Var_Type>::iterator get_Lval(const std::string& identifier) {
        return Stack.top().get_Lval(identifier);
    }
    Field_Sym& get_current_symbol_tbl() {
        return Stack.top();
    }
    int get_current_tbl_size(){return Stack.top().get_current_tbl_size();}
};

extern Symbol_Table SYM_TBL;

enum OperandType {
    OPD_CONSTANT,
    OPD_VARIABLE,
    OPD_ARG,
    OPD_ARGS
};

class Operand {
public:
    Operand(OperandType type, const std::string& value) : type_(type), opd_type_(value) {}
    Operand(OperandType type, const value& value) : type_(type), opd_type_(value) {}
    Operand(OperandType type, const std::vector<Var_Type>& value) : type_(type), opd_type_(value) {}
    Operand() {}
    OperandType getType() const {
        return type_;
    }
    std::variant<std::string, value, std::vector<Var_Type>> getValue() const {
        return opd_type_;
    }
// private:
    OperandType type_;
    std::variant<std::string, value, std::vector<Var_Type>> opd_type_;
};
bool is_a_tmp_param(Var_Type var);
enum inst_IR_type {
    IR_ADD,
    IR_SUB, // sub & minus
    IR_MUL,
    IR_DIV,
    IR_MOD,
    IR_AND,
    IR_OR,
    IR_XOR,
    IR_GT,
    IR_LT,
    IR_GE,
    IR_LE,
    IR_EQ,
    IR_NE,
    IR_LOAD,
    IR_STORE,
    IR_ALLOCATION,
    IR_OFFSET,
    IR_RETURN,
    IR_BRANCH,
    IR_JUMP,
    IR_PANIC, // continue, break...
    IR_FUNCDEF,
    IR_CALL,
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

    Instruction(inst_IR_type type, inst_type inst) : type(type), inst(inst) {print();}
    Instruction(inst_IR_type type, Operand res, Operand opd1, Operand opd2) : type(type) {
        if(type == IR_ADD || type == IR_SUB ||
            type == IR_MUL || type == IR_DIV ||
            type == IR_MOD || type == IR_AND ||
            type == IR_OR || type == IR_XOR ||
            type == IR_GT || type == IR_LT ||
            type == IR_GE || type == IR_LE ||
            type == IR_EQ || type == IR_NE) {
            inst = inst_binary{res, opd1, opd2};
            } else if (type == IR_STORE) {
                inst = inst_store{res, opd1, opd2};
            } else if (type == IR_BRANCH) {
                inst = inst_branch{res, opd1, opd2};
            } else if (type == IR_PANIC) {
                inst = inst_panic{res, opd1, opd2};
            } else if (type == IR_FUNCDEF) {
                inst = inst_funcdef{res, opd1, opd2};
            } else if (type == IR_CALL) {
                inst = inst_call{res, opd1, opd2};
            }
            else assert(false);
            print();
    }
        Instruction(inst_IR_type type, Operand opd1, Operand opd2) : type(type) {
            if (type == IR_LOAD) {
            inst = inst_load{opd1, opd2};
            } else if (type == IR_ALLOCATION) {
            inst = inst_allocation{opd1, opd2};
            } else if (type == IR_OFFSET) {
            inst = inst_offset{opd1, opd2};
            }
            else assert(false);
            print();
            }
        Instruction(inst_IR_type type, Operand res) : type(type) {
            if (type == IR_RETURN) {
            inst = inst_return{res};
            } else if (type == IR_JUMP) {
            inst = inst_jump{res};
            } else if (type == IR_LABEL) {
            inst = inst_label{res};
            }
            else assert(false);
            print();
        }
    void print(){
        if (type == IR_ADD){
            inst_binary instr = get<inst_binary>(inst);
            string res = get<string>(instr.res.opd_type_);
            string opd1 = get<string>(instr.opd1.opd_type_);
            string opd2 = get<string>(instr.opd2.opd_type_);
            if (instr.opd1.type_ == OPD_CONSTANT) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    std::cout << "  let @"<< res << ": i32 = add " << opd1;
                }else{
                    std::cout << "  let %"<< res << ": i32 = add " << opd1;
                }
            } else if (instr.opd1.type_ == OPD_ARG) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    std::cout << "  let @"<< res << ": i32 = add #" << opd1;
                }else{
                    std::cout << "  let %"<< res << ": i32 = add #" << opd1;
                }
                
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            } else {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    if(SYM_TBL.lookup_var(opd1).is_GLOBAL){
                        std::cout << "  let @"<< res << ": i32 = add @" << opd1;
                        if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                            cout << ": i32";
                        } else {
                            cout << ": i32*";
                        }
                    }else{
                        std::cout << "  let @"<< res << ": i32 = add %" << opd1;
                        if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                            cout << ": i32";
                        } else {
                            cout << ": i32*";
                        }
                    }

                }else{
                    if(SYM_TBL.lookup_var(opd1).is_GLOBAL){
                        std::cout << "  let %"<< res << ": i32 = add @" << opd1;
                        if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                            cout << ": i32";
                        } else {
                            cout << ": i32*";
                        }                        
                    }else{
                        std::cout << "  let %"<< res << ": i32 = add %" << opd1;
                        if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                            cout << ": i32";
                        } else {
                            cout << ": i32*";
                        }
                    }

                }

            }
            if (instr.opd2.type_ == OPD_CONSTANT) {
                std::cout << ", " << opd2 << std::endl;
            } else if (instr.opd2.type_ == OPD_ARG) {
                std::cout << ", #" << opd2 << ": i32" << std::endl;
            } else {
                if(SYM_TBL.lookup_var(opd2).is_GLOBAL){
                    std::cout << ", @" << opd2 << ": i32" << std::endl;
                }else
                    std::cout << ", %" << opd2 << ": i32" << std::endl;
            }
        } else if(type == IR_SUB){
            inst_binary instr = get<inst_binary>(inst);
            string res = get<string>(instr.res.opd_type_);
            string opd1 = get<string>(instr.opd1.opd_type_);
            string opd2 = get<string>(instr.opd2.opd_type_);
            if (instr.opd1.type_ == OPD_CONSTANT) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    std::cout << "  let @"<< res << ": i32 = sub " << opd1;
                }else{
                    std::cout << "  let %"<< res << ": i32 = sub " << opd1;
                }
                //std::cout << "  let %"<< res << ": i32 = sub " << opd1;
            } else if (instr.opd1.type_ == OPD_ARG) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    std::cout << "  let @"<< res << ": i32 = sub #" << opd1;
                }else{
                    std::cout << "  let %"<< res << ": i32 = sub #" << opd1;
                }
                //std::cout << "  let %"<< res << ": i32 = sub #" << opd1;
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            } else {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    std::cout << "  let @"<< res << ": i32 = sub %" << opd1;
                }else{
                    std::cout << "  let %"<< res << ": i32 = sub %" << opd1;
                }

                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            }
            if (instr.opd2.type_ == OPD_CONSTANT) {
                std::cout << ", " << opd2 << std::endl;
            } else if (instr.opd2.type_ == OPD_ARG) {
                std::cout << ", #" << opd2 << ": i32" << std::endl;
            } else {
                if(SYM_TBL.lookup_var(opd2).is_GLOBAL){
                    std::cout << ", @" << opd2 << ": i32" << std::endl;
                }else{
                    std::cout << ", %" << opd2 << ": i32" << std::endl;
                }
                
            }
        } else if(type == IR_MUL){
            inst_binary instr = get<inst_binary>(inst);
            string res = get<string>(instr.res.opd_type_);
            string opd1 = get<string>(instr.opd1.opd_type_);
            string opd2 = get<string>(instr.opd2.opd_type_);
            if (instr.opd1.type_ == OPD_CONSTANT) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    std::cout << "  let @"<< res << ": i32 = mul " << opd1;
                }else{
                    std::cout << "  let %"<< res << ": i32 = mul " << opd1;
                }
                
            } else if (instr.opd1.type_ == OPD_ARG) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    std::cout << "  let %"<< res << ": i32 = mul #" << opd1;
                }else{
                    std::cout << "  let %"<< res << ": i32 = mul #" << opd1;
                }
                
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            } else {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    std::cout << "  let @"<< res << ": i32 = mul %" << opd1;
                }else{
                    std::cout << "  let %"<< res << ": i32 = mul %" << opd1;
                }
                
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            }
            if (instr.opd2.type_ == OPD_CONSTANT) {
                std::cout << ", " << opd2 << std::endl;
            } else if (instr.opd2.type_ == OPD_ARG) {
                std::cout << ", #" << opd2 << ": i32" << std::endl;
            } else {
                if(SYM_TBL.lookup_var(opd2).is_GLOBAL){
                    std::cout << ", @" << opd2 << ": i32" << std::endl;
                }else
                std::cout << ", %" << opd2 << ": i32" << std::endl;
            }
        } else if(type == IR_DIV){
            inst_binary instr = get<inst_binary>(inst);
            string res = get<string>(instr.res.opd_type_);
            string opd1 = get<string>(instr.opd1.opd_type_);
            string opd2 = get<string>(instr.opd2.opd_type_);
            if (instr.opd1.type_ == OPD_CONSTANT) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    std::cout << "  let @"<< res << ": i32 = div " << opd1;
                }else
                std::cout << "  let %"<< res << ": i32 = div " << opd1;
            } else if (instr.opd1.type_ == OPD_ARG) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    std::cout << "  let @"<< res << ": i32 = div #" << opd1;
                }else
                std::cout << "  let %"<< res << ": i32 = div #" << opd1;
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            } else {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    std::cout << "  let @"<< res << ": i32 = div %" << opd1;
                }else
                std::cout << "  let %"<< res << ": i32 = div %" << opd1;
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            }
            if (instr.opd2.type_ == OPD_CONSTANT) {
                std::cout << ", " << opd2 << std::endl;
            } else if (instr.opd2.type_ == OPD_ARG) {
                std::cout << ", #" << opd2 << ": i32" << std::endl;
            } else {
                if(SYM_TBL.lookup_var(opd2).is_GLOBAL){
                    std::cout << ", @" << opd2 << ": i32" << std::endl;
                }else
                std::cout << ", %" << opd2 << ": i32" << std::endl;
            }
        } else if(type == IR_MOD){
            inst_binary instr = get<inst_binary>(inst);
            string res = get<string>(instr.res.opd_type_);
            string opd1 = get<string>(instr.opd1.opd_type_);
            string opd2 = get<string>(instr.opd2.opd_type_);
            if (instr.opd1.type_ == OPD_CONSTANT) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    std::cout << "  let @"<< res << ": i32 = rem " << opd1;
                }else
                std::cout << "  let %"<< res << ": i32 = rem " << opd1;
            } else if (instr.opd1.type_ == OPD_ARG) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    std::cout << "  let @"<< res << ": i32 = rem #" << opd1;
                }else
                std::cout << "  let %"<< res << ": i32 = rem #" << opd1;
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            } else {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    if(SYM_TBL.lookup_var(opd1).is_GLOBAL)
                    std::cout << "  let @"<< res << ": i32 = rem @" << opd1;
                    else std::cout << "  let @"<< res << ": i32 = rem %" << opd1;
                }else{
                    if(SYM_TBL.lookup_var(opd1).is_GLOBAL)
                    std::cout << "  let %"<< res << ": i32 = rem @" << opd1;
                    else std::cout << "  let %"<< res << ": i32 = rem %" << opd1;
                }
                
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            }
            if (instr.opd2.type_ == OPD_CONSTANT) {
                std::cout << ", " << opd2 << std::endl;
            } else if (instr.opd2.type_ == OPD_ARG) {
                std::cout << ", #" << opd2 << ": i32" << std::endl;
            } else {
                if(SYM_TBL.lookup_var(opd2).is_GLOBAL)
                std::cout << ", @" << opd2 << ": i32" << std::endl;
                else std::cout << ", %" << opd2 << ": i32" << std::endl;
            }
        } else if(type == IR_AND){
            inst_binary instr = get<inst_binary>(inst);
            string res = get<string>(instr.res.opd_type_);
            string opd1 = get<string>(instr.opd1.opd_type_);
            string opd2 = get<string>(instr.opd2.opd_type_);
            if (instr.opd1.type_ == OPD_CONSTANT) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL)
                std::cout << "  let @"<< res << ": i32 = and " << opd1;
                else std::cout << "  let %"<< res << ": i32 = and " << opd1;
            } else if (instr.opd1.type_ == OPD_ARG) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL)
                std::cout << "  let @"<< res << ": i32 = and #" << opd1;
                else std::cout << "  let %"<< res << ": i32 = and #" << opd1;
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            } else {
                if(SYM_TBL.lookup_var(res).is_GLOBAL)
                std::cout << "  let @"<< res << ": i32 = and %" << opd1;
                else std::cout << "  let %"<< res << ": i32 = and %" << opd1;
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            }
            if (instr.opd2.type_ == OPD_CONSTANT) {
                std::cout << ", " << opd2 << std::endl;
            } else if (instr.opd2.type_ == OPD_ARG) {
                std::cout << ", #" << opd2 << ": i32" << std::endl;
            } else {
                if(SYM_TBL.lookup_var(opd2).is_GLOBAL)
                std::cout << ", @" << opd2 << ": i32" << std::endl;
                else std::cout << ", %" << opd2 << ": i32" << std::endl;
            }
        } else if(type == IR_OR){
            inst_binary instr = get<inst_binary>(inst);
            string res = get<string>(instr.res.opd_type_);
            string opd1 = get<string>(instr.opd1.opd_type_);
            string opd2 = get<string>(instr.opd2.opd_type_);
            if (instr.opd1.type_ == OPD_CONSTANT) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL)
                std::cout << "  let @"<< res << ": i32 = or " << opd1;
                else std::cout << "  let %"<< res << ": i32 = or " << opd1;
            } else if (instr.opd1.type_ == OPD_ARG) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL)
                std::cout << "  let @"<< res << ": i32 = or #" << opd1;
                else std::cout << "  let %"<< res << ": i32 = or #" << opd1;
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            } else {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    if(SYM_TBL.lookup_var(opd1).is_GLOBAL)
                    std::cout << "  let @"<< res << ": i32 = or @" << opd1;
                    else std::cout << "  let @"<< res << ": i32 = or %" << opd1;
                }
                else {
                    if(SYM_TBL.lookup_var(opd1).is_GLOBAL)
                    std::cout << "  let %"<< res << ": i32 = or @" << opd1;
                    else std::cout << "  let %"<< res << ": i32 = or %" << opd1;
                }
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            }
            if (instr.opd2.type_ == OPD_CONSTANT) {
                std::cout << ", " << opd2 << std::endl;
            } else if (instr.opd2.type_ == OPD_ARG) {
                std::cout << ", #" << opd2 << ": i32" << std::endl;
            } else {
                if(SYM_TBL.lookup_var(opd2).is_GLOBAL)
                std::cout << ", @" << opd2 << ": i32" << std::endl;
                else std::cout << ", %" << opd2 << ": i32" << std::endl;
            }
        } else if(type == IR_XOR){
            inst_binary instr = get<inst_binary>(inst);
            string res = get<string>(instr.res.opd_type_);
            string opd1 = get<string>(instr.opd1.opd_type_);
            string opd2 = get<string>(instr.opd2.opd_type_);
            if (instr.opd1.type_ == OPD_CONSTANT) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL)
                std::cout << "  let @"<< res << ": i32 = xor " << opd1;
                else std::cout << "  let %"<< res << ": i32 = xor " << opd1;
            } else if (instr.opd1.type_ == OPD_ARG) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL)
                std::cout << "  let @"<< res << ": i32 = xor #" << opd1;
                else std::cout << "  let %"<< res << ": i32 = xor #" << opd1;
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            } else {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    if(SYM_TBL.lookup_var(opd1).is_GLOBAL)
                    std::cout << "  let @"<< res << ": i32 = xor @" << opd1;
                    else std::cout << "  let @"<< res << ": i32 = xor %" << opd1;
                }else{
                    if(SYM_TBL.lookup_var(opd1).is_GLOBAL)
                    std::cout << "  let %"<< res << ": i32 = xor @" << opd1;
                    else std::cout << "  let %"<< res << ": i32 = xor %" << opd1;
                }
                //std::cout << "  let %"<< res << ": i32 = xor %" << opd1;
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            }
            if (instr.opd2.type_ == OPD_CONSTANT) {
                std::cout << ", " << opd2 << std::endl;
            } else if (instr.opd2.type_ == OPD_ARG) {
                std::cout << ", #" << opd2 << ": i32" << std::endl;
            } else {
                std::cout << ", %" << opd2 << ": i32" << std::endl;
            }
        } else if(type == IR_GT){
            inst_binary instr = get<inst_binary>(inst);
            string res = get<string>(instr.res.opd_type_);
            string opd1 = get<string>(instr.opd1.opd_type_);
            string opd2 = get<string>(instr.opd2.opd_type_);
            if (instr.opd1.type_ == OPD_CONSTANT) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL)
                std::cout << "  let @"<< res << ": i32 = gt " << opd1;
                else std::cout << "  let %"<< res << ": i32 = gt " << opd1;
            } else if (instr.opd1.type_ == OPD_ARG) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL)
                std::cout << "  let @"<< res << ": i32 = gt #" << opd1;
                else std::cout << "  let %"<< res << ": i32 = gt #" << opd1;
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            } else {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    if(SYM_TBL.lookup_var(opd1).is_GLOBAL)
                    std::cout << "  let @"<< res << ": i32 = gt @" << opd1;
                    else std::cout << "  let @"<< res << ": i32 = gt %" << opd1;
                }else{
                    if(SYM_TBL.lookup_var(opd1).is_GLOBAL)
                    std::cout << "  let %"<< res << ": i32 = gt @" << opd1;
                    else std::cout << "  let %"<< res << ": i32 = gt %" << opd1;
                }
                
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            }
            if (instr.opd2.type_ == OPD_CONSTANT) {
                std::cout << ", " << opd2 << std::endl;
            } else if (instr.opd2.type_ == OPD_ARG) {
                std::cout << ", #" << opd2 << ": i32" << std::endl;
            } else {
                if(SYM_TBL.lookup_var(opd2).is_GLOBAL)
                std::cout << ", @" << opd2 << ": i32" << std::endl;
                else std::cout << ", %" << opd2 << ": i32" << std::endl;
            }
        } else if(type == IR_LT){
            inst_binary instr = get<inst_binary>(inst);
            string res = get<string>(instr.res.opd_type_);
            string opd1 = get<string>(instr.opd1.opd_type_);
            string opd2 = get<string>(instr.opd2.opd_type_);
            if (instr.opd1.type_ == OPD_CONSTANT) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL)
                std::cout << "  let @"<< res << ": i32 = lt " << opd1;
                else std::cout << "  let %"<< res << ": i32 = lt " << opd1;
            } else if (instr.opd1.type_ == OPD_ARG) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL)
                std::cout << "  let @"<< res << ": i32 = lt #" << opd1;
                else std::cout << "  let %"<< res << ": i32 = lt #" << opd1;
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            } else {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    if(SYM_TBL.lookup_var(opd1).is_GLOBAL)
                    std::cout << "  let @"<< res << ": i32 = lt @" << opd1;
                    else std::cout << "  let @"<< res << ": i32 = lt %" << opd1;
                }else{
                    if(SYM_TBL.lookup_var(opd1).is_GLOBAL)
                    std::cout << "  let %"<< res << ": i32 = lt @" << opd1;
                    else std::cout << "  let %"<< res << ": i32 = lt %" << opd1;
                }
                //std::cout << "  let %"<< res << ": i32 = lt %" << opd1;
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            }
            if (instr.opd2.type_ == OPD_CONSTANT) {
                std::cout << ", " << opd2 << std::endl;
            } else if (instr.opd2.type_ == OPD_ARG) {
                std::cout << ", #" << opd2 << ": i32" << std::endl;
            } else {
                if(SYM_TBL.lookup_var(opd2).is_GLOBAL)
                std::cout << ", @" << opd2 << ": i32" << std::endl;
                else std::cout << ", %" << opd2 << ": i32" << std::endl;
            }
        } else if(type == IR_GE){
            inst_binary instr = get<inst_binary>(inst);
            string res = get<string>(instr.res.opd_type_);
            string opd1 = get<string>(instr.opd1.opd_type_);
            string opd2 = get<string>(instr.opd2.opd_type_);
            if (instr.opd1.type_ == OPD_CONSTANT) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL)
                std::cout << "  let @"<< res << ": i32 = ge " << opd1;
                else std::cout << "  let %"<< res << ": i32 = ge " << opd1;
            } else if (instr.opd1.type_ == OPD_ARG) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL)
                std::cout << "  let @"<< res << ": i32 = ge #" << opd1;
                else std::cout << "  let %"<< res << ": i32 = ge #" << opd1;
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            } else {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    if(SYM_TBL.lookup_var(opd1).is_GLOBAL)
                    std::cout << "  let @"<< res << ": i32 = ge @" << opd1;
                    else std::cout << "  let @"<< res << ": i32 = ge %" << opd1;
                }else{
                    if(SYM_TBL.lookup_var(opd1).is_GLOBAL)
                    std::cout << "  let %"<< res << ": i32 = ge @" << opd1;
                    else std::cout << "  let %"<< res << ": i32 = ge %" << opd1;
                }
                //std::cout << "  let %"<< res << ": i32 = ge %" << opd1;
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            }
            if (instr.opd2.type_ == OPD_CONSTANT) {
                std::cout << ", " << opd2 << std::endl;
            } else if (instr.opd2.type_ == OPD_ARG) {
                std::cout << ", #" << opd2 << ": i32" << std::endl;
            } else {
                if(SYM_TBL.lookup_var(opd2).is_GLOBAL)
                std::cout << ", @" << opd2 << ": i32" << std::endl;
                else std::cout << ", %" << opd2 << ": i32" << std::endl;
            }
        } else if(type == IR_LE){
            inst_binary instr = get<inst_binary>(inst);
            string res = get<string>(instr.res.opd_type_);
            string opd1 = get<string>(instr.opd1.opd_type_);
            string opd2 = get<string>(instr.opd2.opd_type_);
            if (instr.opd1.type_ == OPD_CONSTANT) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL)
                std::cout << "  let @"<< res << ": i32 = le " << opd1;
                else std::cout << "  let %"<< res << ": i32 = le " << opd1;
            } else if (instr.opd1.type_ == OPD_ARG) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL)
                std::cout << "  let @"<< res << ": i32 = le #" << opd1;
                else std::cout << "  let %"<< res << ": i32 = le #" << opd1;
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            } else {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    if(SYM_TBL.lookup_var(opd1).is_GLOBAL){
                        std::cout << "  let @"<< res << ": i32 = le @" << opd1;

                    }else{
                        std::cout << "  let @"<< res << ": i32 = le %" << opd1;

                    }
                }else{
                    if(SYM_TBL.lookup_var(opd1).is_GLOBAL){
                        std::cout << "  let %"<< res << ": i32 = le @" << opd1;

                    }else{
                        std::cout << "  let %"<< res << ": i32 = le %" << opd1;

                    }
                }
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            }
            if (instr.opd2.type_ == OPD_CONSTANT) {
                std::cout << ", " << opd2 << std::endl;
            } else if (instr.opd2.type_ == OPD_ARG) {
                std::cout << ", #" << opd2 << ": i32" << std::endl;
            } else {
                if(SYM_TBL.lookup_var(opd2).is_GLOBAL)
                std::cout << ", @" << opd2 << ": i32" << std::endl;
                else std::cout << ", %" << opd2 << ": i32" << std::endl;
            }
        } else if(type == IR_EQ){
            inst_binary instr = get<inst_binary>(inst);
            string res = get<string>(instr.res.opd_type_);
            string opd1 = get<string>(instr.opd1.opd_type_);
            string opd2 = get<string>(instr.opd2.opd_type_);
            if (instr.opd1.type_ == OPD_CONSTANT) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL)
                std::cout << "  let @"<< res << ": i32 = eq " << opd1;
                else std::cout << "  let %"<< res << ": i32 = eq " << opd1;
            } else if (instr.opd1.type_ == OPD_ARG) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL)
                std::cout << "  let @"<< res << ": i32 = eq #" << opd1;
                else std::cout << "  let %"<< res << ": i32 = eq #" << opd1;
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            } else {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    if(SYM_TBL.lookup_var(opd1).is_GLOBAL){
                        std::cout << "  let @"<< res << ": i32 = eq @" << opd1;
                    }else{
                        std::cout << "  let @"<< res << ": i32 = eq %" << opd1;
                    }
                }else{
                    if(SYM_TBL.lookup_var(opd1).is_GLOBAL){
                        std::cout << "  let %"<< res << ": i32 = eq @" << opd1;
                    }else{
                        std::cout << "  let %"<< res << ": i32 = eq %" << opd1;
                    }
                }
                
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            }
            if (instr.opd2.type_ == OPD_CONSTANT) {
                std::cout << ", " << opd2 << std::endl;
            } else if (instr.opd2.type_ == OPD_ARG) {
                std::cout << ", #" << opd2 << ": i32" << std::endl;
            } else {
                if(SYM_TBL.lookup_var(opd2).is_GLOBAL)
                std::cout << ", @" << opd2 << ": i32" << std::endl;
                else std::cout << ", %" << opd2 << ": i32" << std::endl;
            }
        } else if(type == IR_NE){
            inst_binary instr = get<inst_binary>(inst);
            string res = get<string>(instr.res.opd_type_);
            string opd1 = get<string>(instr.opd1.opd_type_);
            string opd2 = get<string>(instr.opd2.opd_type_);
            if (instr.opd1.type_ == OPD_CONSTANT) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL)
                std::cout << "  let @"<< res << ": i32 = ne " << opd1;
                else std::cout << "  let %"<< res << ": i32 = ne " << opd1;
            } else if (instr.opd1.type_ == OPD_ARG) {
                if(SYM_TBL.lookup_var(res).is_GLOBAL)
                std::cout << "  let @"<< res << ": i32 = ne #" << opd1;
                else std::cout << "  let %"<< res << ": i32 = ne #" << opd1;
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            } else {
                if(SYM_TBL.lookup_var(res).is_GLOBAL){
                    if(SYM_TBL.lookup_var(opd1).is_GLOBAL)
                    std::cout << "  let @"<< res << ": i32 = ne @" << opd1;
                    else std::cout << "  let @"<< res << ": i32 = ne %" << opd1;
                }else{
                    if(SYM_TBL.lookup_var(opd1).is_GLOBAL)
                    std::cout << "  let %"<< res << ": i32 = ne @" << opd1;
                    else std::cout << "  let %"<< res << ": i32 = ne %" << opd1;
                }
                
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32";
                } else {
                    cout << ": i32*";
                }
            }
            if (instr.opd2.type_ == OPD_CONSTANT) {
                std::cout << ", " << opd2 << std::endl;
            } else if (instr.opd2.type_ == OPD_ARG) {
                std::cout << ", #" << opd2 << ": i32" << std::endl;
            } else {
                if(SYM_TBL.lookup_var(opd2).is_GLOBAL)
                std::cout << ", @" << opd2 << ": i32" << std::endl;
                else std::cout << ", %" << opd2 << ": i32" << std::endl;
            }
        } else if(type == IR_LOAD){
            inst_load instr = get<inst_load>(inst);
            string res = get<string>(instr.target.opd_type_);
            string opd = get<string>(instr.source.opd_type_);
            if (instr.target.type_ == OPD_CONSTANT) {
                std::cout << "  let " << res;
            } else if (instr.target.type_ == OPD_ARG) {
                std::cout << "  let #" << res;
            } else {
                if(SYM_TBL.lookup_var(res).is_GLOBAL)
                std::cout << "  let @" << res;
                else std::cout << "  let %" << res;
            }
            if (instr.source.type_ == OPD_CONSTANT) {
                std::cout << ": i32 = load " << opd << ": i32*" << std::endl;
            } else if (instr.source.type_ == OPD_ARG) {
                std::cout << ": i32 = load #" << opd << ": i32*" << std::endl;
            } else {
                //cout<<endl<<"HEHE "<<SYM_TBL.lookup_var(opd).is_GLOBAL<<"opd name: "<<opd<<endl;
                if(SYM_TBL.lookup_var(opd).is_GLOBAL)
                std::cout << ": i32 = load @" << opd << ": i32*" << std::endl;
                else std::cout << ": i32 = load %" << opd << ": i32*" << std::endl;
            }
        } else if(type == IR_STORE){
            inst_store instr = get<inst_store>(inst);
            string res = get<string>(instr.res.opd_type_);
            string opd1 = get<string>(instr.opd1.opd_type_);
            string opd2 = get<string>(instr.opd2.opd_type_);
            if (instr.opd1.type_ == OPD_ARG) {
                if(false){
                    if(SYM_TBL.lookup_var(opd2).is_GLOBAL){
                        std::cout << "  let @"<< res << ": () = store #" << opd1 << ", @" << opd2 << ": i32*" << std::endl;
                    }else{
                        std::cout << "  let @"<< res << ": () = store #" << opd1 << ", %" << opd2 << ": i32*" << std::endl;
                    }
                }else{
                    if(SYM_TBL.lookup_var(opd2).is_GLOBAL){
                        std::cout << "  let %"<< res << ": () = store #" << opd1 << ", @" << opd2 << ": i32*" << std::endl;
                    }else{
                        std::cout << "  let %"<< res << ": () = store #" << opd1 << ", %" << opd2 << ": i32*" << std::endl;
                    }
                }
                
            }
            else if (instr.opd1.type_ == OPD_CONSTANT) {
                std::cout << "  let %"<< res << ": () = store " << opd1 << ", %" << opd2 << ": i32*" << std::endl;
            }
            else{
                 std::cout << "  let %"<< res << ": () = store %" << opd1;
                if (SYM_TBL.lookup_var(opd1).type == INT_TY) {
                    cout << ": i32, %" << opd2 << ": i32*" << std::endl;
                } else {
                    cout << ": i32*, %" << opd2 << ": i32*" << std::endl;
                }
            }
        } else if(type == IR_ALLOCATION){
            inst_allocation instr = get<inst_allocation>(inst);
            string res = get<string>(instr.res.opd_type_);
            value opd_ = get<value>(instr.ElementNum.opd_type_);
            int opd = get<int>(opd_);
            std::cout << "  let %"<< res << ": i32* = alloca i32, " << opd << std::endl;
        } else if(type == IR_OFFSET){
            //to do
        } else if(type == IR_RETURN){            
            inst_return instr = get<inst_return>(inst);
            string res = get<string>(instr.res.opd_type_);
            std::cout << "  ret %"<< res << ": i32" << std::endl << "}" << endl << endl;
        } else if(type == IR_BRANCH){
            inst_branch instr = get<inst_branch>(inst);
            string cond = get<string>(instr.cond.opd_type_);
            string True_label = get<string>(instr.True_label.opd_type_);
            string False_label = get<string>(instr.False_label.opd_type_);
            std::cout << "  br %"<< cond << ": i32, label %" << True_label << ", label %" << False_label << std::endl;

        } else if(type == IR_JUMP){
            inst_jump instr = get<inst_jump>(inst);
            string label = get<string>(instr.dest.opd_type_);
            std::cout << "  jmp label %" << label << std::endl;
        } else if(type == IR_PANIC){
            //to do
        } else if(type == IR_FUNCDEF){
            inst_funcdef instr = get<inst_funcdef>(inst);
            string f_name = get<string>(instr.f_name.opd_type_);
            string return_type = get<string>(instr.return_type.opd_type_);
            if(return_type == "INT"){
                return_type = "i32";
            }else if(return_type == "VOID"){
                return_type = "()";
            }
            std::cout << "fn @" << f_name<<"(";
            vector<Var_Type> args = get<vector<Var_Type>>(instr.arg_types.opd_type_);
            bool first = true; // 用于控制参数间的逗号
            for (auto arg : args) {
                string name = arg.tmp_var_name;
                if (arg.type == NONE) {
                    break;
                }
                if (!first) {
                    std::cout << ", ";
                }
                first = false;
                // 判断参数类型并输出相应类型
                std::string arg_type;
                switch (arg.type) {
                    case INT_TY:
                        arg_type = "i32";
                        break;
                    default:
                        arg_type = "i32*";
                        break;
                }
                std::cout << "#" << name << ": " << arg_type;
            }
            std::cout << ") -> " << return_type << " {" << std::endl;
        } else if(type == IR_CALL){
            inst_call instr = get<inst_call>(inst);
            string res = get<string>(instr.res.opd_type_);
            string func = get<string>(instr.func.opd_type_);
            Func_Type function = SYM_TBL.lookup_func(func);
            if (function.return_type == INT_TY) {
                std::cout << "  let %" << res << ": i32 = call @" << func;
            } else {
                std::cout << "  let %" << res << ": () = call @" << func;
            }
            vector<Var_Type> args = get<vector<Var_Type>>(instr.args.opd_type_);
            for (auto arg : args){
                string name = arg.tmp_var_name;
                if (arg.type == NONE) {
                    std::cout << ", " << name;
                } else if (is_a_tmp_param(arg)) {
                    std::cout << ", #" << name;
                    if (arg.type == INT_TY) {
                        std::cout << ": i32";
                    } else {
                        std::cout << ": i32*";
                    }
                } else {
                    std::cout << ", %" << name;
                    //cout << endl << SYM_TBL.lookup_var(name).type << endl;
                    if (arg.type == INT_TY) {
                        std::cout << ": i32";
                    } else {
                        std::cout << ": i32*";
                    }
                }
            }
            std::cout << std::endl;
        } else if(type == IR_LABEL){
            inst_label instr = get<inst_label>(inst);
            string label = get<string>(instr.label.opd_type_);
            std::cout << "%" << label << ":" << std::endl;
        } else{
            assert(false);
        }
    }
    inst_IR_type type;
    inst_type inst;
};

struct BasicBlock{
    std::vector<Instruction> inst_list;
    std::string name;
    BasicBlock(std::vector<Instruction> inst_list, std::string name) : inst_list(inst_list), name(name) {}
    BasicBlock& operator=(const BasicBlock& b){
        if(this != &b){
            inst_list = b.inst_list;
            name = b.name;
        }
        return *this;
    }
} ;

typedef std::vector<BasicBlock> BBs;

bool canConvertToInt(const std::string& str);
ir_Type translate_expr(Node expr, Symbol_Table& symbol_table, BasicBlock current_bb);
Expr_Stmt_type get_exprType_from_node(Node *node);
BasicBlock translate_stmt(Node stmt, Symbol_Table& symbol_table, BasicBlock current_bb);
void init_libs();
void traverseTree(Node node);
#endif