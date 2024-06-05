#include <ir/ir.h>
bool canConvertToInt(const std::string& str) {
    if (str.empty()) {
        return false;
    }
    
    size_t start = 0;
    if (str[0] == '-' || str[0] == '+') { // Handle optional sign
        if (str.length() == 1) {
            return false; // "+" or "-" alone is not a valid integer
        }
        start = 1;
    }

    for (size_t i = start; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool startsWith(const std::string& str, const std::string& prefix) {
    return str.substr(0, prefix.length()) == prefix;
}

enum unary_ty{
    NOT_UNARY,
    ADD,
    SUB,
    NOT
};
// unary_ty is_current_operation_exp_node_unary(Node& expr){
//     auto& children=expr.children;
//     for(auto& child : children){
//         if(get_exprTpye_from_node(&child)==ARRAY_et||get_exprTpye_from_node(&child)==BinOp_et||get_exprTpye_from_node(&child)==ID_et)
//     }
// }
string get_unary_type(Node& expr){//不能handal极端复杂情况如 ++-------++！！！！！+++--
    auto& children = expr.children;
    int sub=0;
    int Not=0;
    int first_ADD=0;
    int first_SUB=0;
    int first_NOT=0;
    int first=1;
    for(auto& child : children){
        if(child.name()=="ADD") {
            if(child.children_size()==0){
                first_ADD+=first;
                first=0;
            }

        }
        if(child.name()=="SUB") {
            if(child.children_size()==0){
                first_SUB+=first;
                first=0;
                sub++;
            }
        }
        if(child.name()=="NOT") {
            if(child.children_size()==0){
                first_NOT+=first;
                first=0;
                Not++;
            }
        }

    }
    if(first_ADD){
        return "ADD";
    }
    if(first_SUB&&sub%2!=0){
        return "SUB";
    }
    if(first_NOT&&Not%2!=0){
        return "NOT";
    }
    cout<<"err in get_unary_type, NOT UNARY!!!"<<endl;
}


Expr_Stmt_type get_exprTpye_from_node(Node *node) {
    string name = node->name();
    
    if (canConvertToInt(name)) {
        return INT_et;
    } 
    else if (startsWith(name, "LVal")) {
        // LVal ID
        return useless_est;
    } 
    else if (startsWith(name, "FucDef")) {
        // FucDef ID returnType(VOID or INT)
        return FucDef_est;
    } 
    else if (startsWith(name, "INT")) {
        // INT VarDecl
        return useless_est;
    }
    
    if (name == "ADD"|| name == "SUB"|| name == "MUL" || name == "DIV" || name == "MOD" || name == "GT" || name == "LT" ||
        name == "LE" || name == "GE" || name == "EQ" || name == "NE" || 
        name == "OR" || name == "AND") {
        for (auto child : node->children) {
            if ((child.name() == "SUB" && child.children_size() == 0) || 
                (child.name() == "NOT" && child.children_size() == 0)) {
                return Unary_BinOp_et;
            }
        }
        return BinOp_et;
    }
    else if (name == "NOT"){
        return useless_est;
    }
    else if (name == "AssignStmt"){
        return Assign_st;
    }
    else if (name == "ExpStmt"){
        return Expr_st;
    }else if (name == "IfStmt"){
        return If_st;
    }
    else if (name == "IfElseStmt"){
        return IfElse_st;
    }
    else if (name == "BreakStmt"){
        return useless_est;
    }
    else if (name == "WhileStmt"){
        return While_st;
    }
    else if (name == "ContinueStmt"){
        return useless_est;
    }
    else if (name == "ReturnStmt"){
        return Return_st;
    }
    else if (name == "Exps"){
        return useless_est;
    }
    else if (name == "ConstGroup"){
        return useless_est;
    }
    else if (name == "FuncFParams"){
        return useless_est;
    }
    else if (name == "FuncRParams"){
        return useless_est;
    }
    else if (name == "VerDefGroup"){
        return useless_est;
    }
    else if (name == "VerDef"){
        if (node->get(0)->get_type() == INT_TY){
            return VarDecl_st;
        }
        else{
            return VarDeclArray_st;
        }
    }
    else if (name == "Block"){
        return useless_est;
    }
    else if (name == "BlockItems") {
        return useless_est;
    } 
    else {
        if(node->get(0)->name() == "FuncRParams") {
            return Call_et;
        }
        else if(node->get_type() == INT_TY){
            for (auto child : node->children) {
                if ((child.name() == "SUB" && child.children_size() == 0) || 
                    (child.name() == "NOT" && child.children_size() == 0)) {
                    return Unary_ID_et;
                }
            }
            return ID_et;
        }
        else{
            for (auto child : node->children) {
                if ((child.name() == "SUB" && child.children_size() == 0) || 
                    (child.name() == "NOT" && child.children_size() == 0)) {
                    return Unary_ARRAY_et;
                }
            }
            return ARRAY_et;
        }
    }
    return useless_est;
}

void insert_instruction(Instruction& inst, BasicBlock cur_block) {
    vector<Instruction>& cur_BB = (*(cur_block.iter_to_BBs))[cur_block.current_bb];
    cur_BB.push_back(inst);
    // std::vector<string > instrs = BBs[cur_block];
    // instrs.push_back(inst);
}


ir_Type create_constant(int number, Type type){
    Var_Type ret;
    ret.type = type;
    value val;
    val = number;
    ret.val = val;
    return ret;

}
std::unordered_map<std::string, Var_Type>::iterator create_load(std::unordered_map<std::string, Var_Type>::iterator addr, BasicBlock& current_bb){//这里的addr实际就是变量的iterator，类似于指针
    //创建inst条目
    Var_Type *target=new Var_Type();
    target->tmp_var_name="tmp_"+addr->first;
    target->type=addr->second.type;
    target->val=addr->second.val;

    auto op_target = new Operand(OPD_VARIABLE,target->tmp_var_name);
    auto op_source = new Operand(OPD_VARIABLE, addr->first);
    auto inst = new Instruction(IR_LOAD, *op_target, *op_source);

    insert_instruction(*inst, current_bb);
    // vector<Instruction>& cur_BB = (*(current_bb.iter_to_BBs))[current_bb.current_bb];
    // cur_BB.push_back(*inst);
    //inst条目创建、插入BB完毕
    return addr;
}//load重要的就是target and source   
ir_Type create_binary(string operation, ir_Type exp1, ir_Type exp2, BasicBlock current_bb){
    if(operation=="ADD"){
        auto& e1=get<Var_Type>(exp1);
        auto& e2=get<Var_Type>(exp2);

        int v1=get<int>(e1.val);
        int v2=get<int>(e2.val);
        int v=v1+v2;

        Var_Type ret;
        ret.type=INT_TY;
        ret.val=v;
        //inst 创建
        auto res = new Operand()
        return ret;

    }else if("AND"){
        auto& e1=get<Var_Type>(exp1);
        auto& e2=get<Var_Type>(exp2);

        int v1=get<int>(e1.val);
        int v2=get<int>(e2.val);
        int v=v1&&v2;

        Var_Type ret;
        ret.type=INT_TY;
        ret.val=v;

        return ret;

    }else if("SUB"){
        auto& e1=get<Var_Type>(exp1);
        auto& e2=get<Var_Type>(exp2);

        int v1=get<int>(e1.val);
        int v2=get<int>(e2.val);
        int v=v1-v2;

        Var_Type ret;
        ret.type=INT_TY;
        ret.val=v;

        return ret;
    }

}

ir_Type translate_expr(Node expr,Symbol_Tabel symbol_table,BasicBlock current_bb){
    Expr_Stmt_type exp_type=get_exprTpye_from_node(&expr);

    if (exp_type == INT_et) {
        int number = std::stoi(expr.type);
        return create_constant(number, INT_TY);

    } else if (exp_type == ID_et) {
        auto iter=symbol_table.get_Lval(expr.name());
        
        return create_load(iter,current_bb);
    } else if (exp_type == BinOp_et) {
        auto operation=expr.name();
        auto expr1_value=translate_expr(expr.children[0], symbol_table,current_bb);
        auto expr2_value=translate_expr(expr.children[1], symbol_table,current_bb);

        return create_binary(operation,expr1_value,expr2_value,current_bb);
        
        // Handle BinOp_et case
    } else if (exp_type == Unary_ARRAY_et||exp_type == Unary_BinOp_et||exp_type == Unary_ID_et) {
        string U_TY=get_unary_type(expr);
        auto zero_exp=create_constant(0, INT_TY);
        auto expr1_value= translate_expr(expr,symbol_table,current_bb);
        // Handle MINUS_et case
    } else if (exp_type == Call_et) {
        // Call ID, Args
        string ID = expr.get_id();
        Func_Type func = symbol_table.lookup_func(ID);
        std::vector<ir_Type *> args_l;
        // node(ID) -> child(FuncRParams)->children(Arg, Arg, Arg, ...)
        std::vector<Node> Args = expr.get(0)->children;
        for (auto arg : Args) {
            // string arg_string = arg->name();
            ir_Type translated_arg = translate_expr(arg, symbol_table, current_bb);
            Type arg_temp = get<Var_Type>(translated_arg).type;
            func.args.push_back(arg_temp);
        }
        return func;
    }
    else if (exp_type == ARRAY_et) {
        // ID[Idx1]..[IdxN]
        string ID = expr.get_id();
        Var_Type &array = symbol_table.lookup_var(ID);
        Type array_type = array.type;
        value array_value = array.val;
        int result_temp;
        Var_Type result;
        result.type = INT_TY;
        if (array_type == ARRAY){
            int idx1 = atoi(expr.get(0)->name().c_str());
            result_temp = get<1>(array_value)[idx1];
        }
        else if(array_type ==LIST_2){
            int idx1 = atoi(expr.get(0)->name().c_str());            
            int idx2 = atoi(expr.get(1)->name().c_str());
            result_temp = get<2>(array_value)[idx1][idx2];
        }
        else if(array_type ==LIST_3){
            int idx1 = atoi(expr.get(0)->name().c_str());
            int idx2 = atoi(expr.get(1)->name().c_str());
            int idx3 = atoi(expr.get(2)->name().c_str());
            result_temp = get<3>(array_value)[idx1][idx2][idx3];
        }
        else if(array_type ==LIST_4){
            int idx1 = atoi(expr.get(0)->name().c_str());
            int idx2 = atoi(expr.get(1)->name().c_str());
            int idx3 = atoi(expr.get(2)->name().c_str());
            int idx4 = atoi(expr.get(3)->name().c_str());
            result_temp = get<4>(array_value)[idx1][idx2][idx3][idx4];
        }
        else if(array_type ==LIST_5){
            int idx1 = atoi(expr.get(0)->name().c_str());
            int idx2 = atoi(expr.get(1)->name().c_str());
            int idx3 = atoi(expr.get(2)->name().c_str());
            int idx4 = atoi(expr.get(3)->name().c_str());
            int idx5 = atoi(expr.get(4)->name().c_str());
            result_temp = get<5>(array_value)[idx1][idx2][idx3][idx4][idx5];
        }
        result.val = result_temp;
        return result;
    }


}
Var_Type create_alloca(Var_Type var, int size, BasicBlock current_bb){
    auto res = new Operand(OPD_VARIABLE, var.tmp_var_name);
    auto size_ = new Operand(OPD_CONSTANT, size);
    auto inst = new Instruction(IR_ALLOCATION, *res, *size_);

    insert_instruction(*inst, current_bb);

    Var_Type tmp;
    tmp.tmp_var_name="tmp"+var.tmp_var_name;
    tmp.type = var.type;
    return tmp;

}//alloca 重要的是size和name，type固定为 i32；size和name在vartype和value里分别找到


BasicBlock translate_stmt(Node stmt,Symbol_Tabel symbol_table,BasicBlock current_bb){
    Expr_Stmt_type stmt_type=get_exprTpye_from_node(&stmt);
    if (stmt_type == VarDecl_st) {
        unordered_map<string, std::vector<std::vector<Instruction>>>::iterator iter = Func_BB_map.find(cur_Func);
        BasicBlock entry_bb;
        entry_bb.iter_to_BBs = (iter->second).begin();
        entry_bb.current_bb = 0;//enrty block

        string name = (stmt.children)[0].name();
        Var_Type tmp;
        tmp.tmp_var_name = name;
        tmp.type = INT_TY;
        SYM_TBL.add_symbol(name, tmp);
        //auto var_type = SYM_TBL.lookup_var(name);
        Var_Type alloca_instr = create_alloca(tmp,1,current_bb);
        SYM_TBL.add_symbol(alloca_instr.tmp_var_name, alloca_instr);
        
        return current_bb;//??????why

        // Handle variable declaration statement
    } else if (stmt_type == VarDeclArray_st) {
        // Handle variable declaration array statement
    } else if (stmt_type == Expr_st) {
        // Handle expression statement
    } else if (stmt_type == Assign_st) {
        // Handle assignment statement
    } else if (stmt_type == If_st) {
        // Handle if statement
    } else if (stmt_type == IfElse_st) {
        // Handle if-else statement
    } else if (stmt_type == While_st) {
        // Handle while statement
    } else if (stmt_type == Return_st) {
        // Handle return statement
    } else {
        // Handle other cases or error
    }




}