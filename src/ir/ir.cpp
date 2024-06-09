#include <ir/ir.h>


extern int bb_num;

extern std::unordered_map<std::string, BBs> Func_BB_map; // LOCAL, for func's basic blocks.
extern std::string cur_Func;
extern vector<Var_Type> cur_params;
extern Symbol_Table SYM_TBL;

void reverseVector(std::vector<Node>& params_) {
    std::reverse(params_.begin(), params_.end());
}
extern std::set<std::string> GLOBALs;

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
    // cout<<"err in get_unary_type, NOT UNARY!!!"<<endl;
    // assert(false);
    return "ADD";
}


Expr_Stmt_type get_exprTpye_from_node(Node *node) {
    string name = node->name();
    
    if (canConvertToInt(name)) {
        for (auto child : node->children) {
            if ((child.type == "SUB" && child.children_size() == 0) || 
                (child.type == "NOT" && child.children_size() == 0)) {
                return Unary_ID_et;
            }
        }
        return INT_et;
    } 
    else if (startsWith(name, "LVal")) {
        // LVal ID
        if(node->t == INT_TY){
            for (auto child : node->children) {
                if ((child.type == "SUB" && child.children_size() == 0) || 
                    (child.type == "NOT" && child.children_size() == 0)) {
                    return Unary_ID_et;
                }
                else {
                    // cout<<"INASDASDA"<<endl;
                    return ARRAY_et;
                }
            }
            // cout<<"ININTTY"<<endl;
            return ID_et;
        } else {
            // cout<<"INASDASDA"<<endl;
            return ARRAY_et;
        }
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
    else if (name == "ReturenStmt"){
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
        return Block_st;
    }
    else if (name == "BlockItems") {
        return useless_est;
    } 
    else {
        // cout << "judge function : " << node->ID << endl;
        Func_Type func;
        func.tmp_arg_name = {"NOT_FOUND"};
        if (SYM_TBL.Stack.top().Func_sym_tbl.size() != 0) {
            func = SYM_TBL.lookup_func(node->type);
        }
        if(func.tmp_arg_name.size() != 1 || func.tmp_arg_name[0] != "NOT_FOUND") {
            return Call_et;
        }
        else if(node->t == INT_TY){
            for (auto child : node->children) {
                if ((child.type == "SUB" && child.children_size() == 0) || 
                    (child.type == "NOT" && child.children_size() == 0)) {
                    return Unary_ID_et;
                }
            }
            return ID_et;
        }
        else{
            for (auto child : node->children) {
                if ((child.type == "SUB" && child.children_size() == 0) || 
                    (child.type == "NOT" && child.children_size() == 0)) {
                    return Unary_ARRAY_et;
                }
            }
            return ARRAY_et;
        }
    }
    return useless_est;
}

void insert_instruction(Instruction& inst, BasicBlock cur_block) {
    cur_block.inst_list.push_back(inst);
}


ir_Type create_constant(int number, Type type){
    Var_Type ret;
    ret.type = NONE;
    value val;
    val = number;
    ret.val = val;
    ret.tmp_var_name = to_string(number);
    return ret;

}

void create_load(Var_Type target, Var_Type source, BasicBlock& current_bb){

    auto tar = new Operand;
    auto src = new Operand;

    if (is_a_tmp_param(target)) {
        tar = new Operand(OPD_ARG, target.tmp_var_name);
    } else {
        tar = new Operand(OPD_VARIABLE, target.tmp_var_name);
    }

    if (is_a_tmp_param(source)) {
        src = new Operand(OPD_VARIABLE, source.tmp_var_name+".addr");
    } else {
        src = new Operand(OPD_VARIABLE, source.tmp_var_name);
    }
    // auto tar = new Operand(OPD_VARIABLE, target.tmp_var_name);
    // auto src = new Operand(OPD_VARIABLE, source.tmp_var_name);
    auto inst = new Instruction(IR_LOAD, *tar,*src);
    insert_instruction(*inst, current_bb);
}//load重要的就是target and source   

// std::unordered_map<std::string, Var_Type>::iterator create_load(std::unordered_map<std::string, Var_Type>::iterator addr, BasicBlock& current_bb){//这里的addr实际就是变量的iterator，类似于指针
//     //创建inst条目
//     Var_Type *target=new Var_Type();
//     target->tmp_var_name="tmp_"+addr->first;
//     target->type=addr->second.type;
//     target->val=addr->second.val;

//     auto op_target = new Operand(OPD_VARIABLE,target->tmp_var_name);
//     auto op_source = new Operand(OPD_VARIABLE, addr->first);
//     auto inst = new Instruction(IR_LOAD, *op_target, *op_source);

//     insert_instruction(*inst, current_bb);
//     // vector<Instruction>& cur_BB = (*(current_bb.iter_to_BBs))[current_bb.current_bb];
//     // cur_BB.push_back(*inst);
//     //inst条目创建、插入BB完毕
//     return addr;
// }//load重要的就是target and source
void create_binary(string operation,Var_Type BinOpRes, Var_Type exp1, Var_Type exp2, BasicBlock current_bb){
    auto BOR = new Operand(OPD_VARIABLE, BinOpRes.tmp_var_name);
    auto e1 = new Operand;
    auto e2 = new Operand;

    if (is_a_tmp_param(exp1)) {
        e1 = new Operand(OPD_ARG, exp1.tmp_var_name);
    } else if (exp1.type == NONE) {
        e1 = new Operand(OPD_CONSTANT, exp1.tmp_var_name);        
    } else {
        e1 = new Operand(OPD_VARIABLE, exp1.tmp_var_name);
    }

    if (is_a_tmp_param(exp2)) {
        e2 = new Operand(OPD_ARG, exp2.tmp_var_name+".addr");
    } else if (exp2.type == NONE) {
        e2 = new Operand(OPD_CONSTANT, exp2.tmp_var_name);        
    } else {
        e2 = new Operand(OPD_VARIABLE, exp2.tmp_var_name);
    }


    if(operation=="ADD"){
        auto inst = new Instruction(IR_ADD,*BOR,*e1,*e2);
        insert_instruction(*inst,current_bb);


    }else if(operation=="AND"){
        auto inst = new Instruction(IR_AND,*BOR,*e1,*e2);
        insert_instruction(*inst,current_bb);
    }else if(operation=="SUB"){
        //cout<<"IN SUB brc";
        auto inst = new Instruction(IR_SUB,*BOR,*e1,*e2);
        insert_instruction(*inst,current_bb);
    }else if(operation=="GT"){
        auto inst = new Instruction(IR_GT,*BOR,*e1,*e2);
        insert_instruction(*inst,current_bb);
    }else if(operation=="GE"){
        auto inst = new Instruction(IR_GE,*BOR,*e1,*e2);
        insert_instruction(*inst,current_bb);
    }else if(operation=="DIV"){
        auto inst = new Instruction(IR_DIV,*BOR,*e1,*e2);
        insert_instruction(*inst,current_bb);
    }else if(operation=="EQ"){
        auto inst = new Instruction(IR_EQ,*BOR,*e1,*e2);
        insert_instruction(*inst,current_bb);
    }else if(operation=="LE"){
        auto inst = new Instruction(IR_LE,*BOR,*e1,*e2);
        insert_instruction(*inst,current_bb);
    }else if(operation=="LT"){
        auto inst = new Instruction(IR_LT,*BOR,*e1,*e2);
        insert_instruction(*inst,current_bb);
    }else if(operation=="MOD"){
        auto inst = new Instruction(IR_MOD,*BOR,*e1,*e2);
        insert_instruction(*inst,current_bb);
    }else if(operation=="MUL"){
        auto inst = new Instruction(IR_MUL,*BOR,*e1,*e2);
        insert_instruction(*inst,current_bb);
    }else if(operation=="NE"){
        auto inst = new Instruction(IR_NE,*BOR,*e1,*e2);
        insert_instruction(*inst,current_bb);
    }else if(operation=="OR"){
        auto inst = new Instruction(IR_OR,*BOR,*e1,*e2);
        insert_instruction(*inst,current_bb);
    }else if(operation=="XOR"){
        auto inst = new Instruction(IR_XOR,*BOR,*e1,*e2);
        insert_instruction(*inst,current_bb);
    }
    

    
    
}   
// ir_Type create_binary(string operation, ir_Type exp1, ir_Type exp2, BasicBlock current_bb){
//     if(operation=="ADD"){
//         auto& e1=get<Var_Type>(exp1);
//         auto& e2=get<Var_Type>(exp2);

//         // int v1=get<int>(e1.val);
//         // int v2=get<int>(e2.val);
//         // int v=v1+v2;

//         Var_Type ret;
//         ret.type=INT_TY;
//         ret.val=v;
//         //inst 创建
//         auto res = new Operand()
//         return ret;

//     }else if("AND"){
//         auto& e1=get<Var_Type>(exp1);
//         auto& e2=get<Var_Type>(exp2);

//         int v1=get<int>(e1.val);
//         int v2=get<int>(e2.val);
//         int v=v1&&v2;

//         Var_Type ret;
//         ret.type=INT_TY;
//         ret.val=v;

//         return ret;

//     }else if("SUB"){
//         auto& e1=get<Var_Type>(exp1);
//         auto& e2=get<Var_Type>(exp2);

//         int v1=get<int>(e1.val);
//         int v2=get<int>(e2.val);
//         int v=v1-v2;

//         Var_Type ret;
//         ret.type=INT_TY;
//         ret.val=v;

//         return ret;
//     }

// }

void create_branch(string cond, string true_label, string false_label, BasicBlock current_bb){
    Operand op1 = Operand(OPD_VARIABLE, cond);
    Operand op2 = Operand(OPD_VARIABLE, true_label);
    Operand op3 = Operand(OPD_VARIABLE, false_label);
    Instruction new_inst = Instruction(IR_BRANCH, op1, op2, op3);
    current_bb.inst_list.push_back(new_inst);
    // insert_instruction(new_inst, current_bb);
}

void create_jump(string exit_bb, BasicBlock current_bb){
    Operand op1 = Operand(OPD_VARIABLE, exit_bb);
    Instruction new_inst = Instruction(IR_JUMP, op1);
    current_bb.inst_list.push_back(new_inst);
    // insert_instruction(new_inst, current_bb);
}

void create_ret(string exit_bb, Symbol_Table& symbol_table, BasicBlock current_bb){
    BBs bbs = Func_BB_map[cur_Func];

    Instruction inst_jmp = Instruction(IR_JUMP, Operand(OPD_VARIABLE, "exit"));
    current_bb.inst_list.push_back(inst_jmp);

    string ret_name = "after_return" + to_string(symbol_table.get_current_tbl_size());
    Instruction inst_label = Instruction(IR_LABEL, Operand(OPD_VARIABLE, ret_name));
    vector<Instruction> label1 = {inst_label};
    BasicBlock after_return = BasicBlock(label1, ret_name);
    // Instruction inst_jmp2 = Instruction(IR_JUMP, Operand(OPD_VARIABLE, "exit"));
    // after_return.inst_list.push_back(inst_jmp2);
    bbs.push_back(after_return);

    // insert_instruction(new_inst, current_bb);
}

void create_function_call(Func_Type func, string ID, string res, Symbol_Table& symbol_table, BasicBlock current_bb){
    Operand result = Operand(OPD_VARIABLE, res);
    Operand func_name = Operand(OPD_VARIABLE, ID);
    vector<Var_Type> args;
    vector<string> arg_names = func.tmp_arg_name;
    for(int i = 0; i < arg_names.size(); i++){
        string name = arg_names[i]; 
        Var_Type tmp;
        tmp.type = func.args[i];
        if (tmp.type == NONE) {
            tmp.tmp_var_name = name;
        }
        else {
            //cout<<"YOU?"<<endl;
            tmp = symbol_table.lookup_var(name);  
        }
        args.push_back(tmp);
    }
    Operand args_op = Operand(OPD_ARGS, args);
    Instruction new_inst = Instruction(IR_CALL, result, func_name, args_op);
    current_bb.inst_list.push_back(new_inst);
}

void create_store(string opd1, string opd2, BasicBlock current_bb, int opd1_type = 0){
    string res = "res";
    Operand result = Operand(OPD_VARIABLE, res);
    Operand op1 = Operand(OPD_VARIABLE, opd1);
    if (opd1_type == 1) {
        op1.type_ = OPD_ARG;
    }
    else if(opd1_type == 2){
        op1.type_ = OPD_CONSTANT;
    }

    Var_Type tmp;
    tmp.tmp_var_name = opd2;
    if (is_a_tmp_param(tmp)) {
        Operand op2 = Operand(OPD_VARIABLE, opd2 + ".addr");
        Instruction new_inst = Instruction(IR_STORE, result, op1, op2);
        current_bb.inst_list.push_back(new_inst);
    }
    else {
        Operand op2 = Operand(OPD_VARIABLE, opd2);
        Instruction new_inst = Instruction(IR_STORE, result, op1, op2);
        current_bb.inst_list.push_back(new_inst);
    }
}
bool isDigitString(const std::string& s) {
    return std::all_of(s.begin(), s.end(), ::isdigit);
}
void create_offset(string arr_ids, string arr_name,vector<string> ids,Symbol_Table symbol_table){
    //cout<<"YOU??"<<endl;
    auto var = symbol_table.lookup_var(arr_name);
    auto vec = var.val;
    vector<int> size=get<1>(var.val);
    if(SYM_TBL.lookup_var(arr_name).is_GLOBAL)
        cout<<" let %"<<arr_ids<<": i32* = offset i32, @"<<arr_name<<": i32*";
    else
     cout<<" let %"<<arr_ids<<": i32* = offset i32, %"<<arr_name<<": i32*";
    int sz=ids.size();
    for(int i=0;i<sz;i++){
        cout<<", ["<<ids[i]<<" < "<<to_string(size[i])<<"]";
    }
    cout<<endl;

}
ir_Type translate_expr(Node expr,Symbol_Table& symbol_table,BasicBlock current_bb){
    Expr_Stmt_type exp_type=get_exprTpye_from_node(&expr);
    // cout << exp_type << endl;
    if (exp_type < 0 || exp_type >7){
        cout << exp_type << endl;
        assert(0);
    }
    if (exp_type == INT_et) {
        int number = std::stoi(expr.type);
        return create_constant(number, INT_TY);

    } else if (exp_type == ID_et) {
        // for (auto i : symbol_table.Stack.top().Var_sym_tbl){
        //     cout << "first:" << i.first << endl;
        // }
        Var_Type tar;
        tar.tmp_var_name = to_string(symbol_table.get_current_tbl_size());
        tar.type = INT_TY;
        tar.val = 0;//default
        symbol_table.add_symbol(tar.tmp_var_name,tar);

        string ID = expr.name();
        std::regex pattern("LVal\\s*(.+)");
        std::smatch match;
        if (std::regex_search(ID, match, pattern)){
            ID = match[1];
        }


        // Var_Type src = symbol_table.lookup_var(ID);
        // if (src.tmp_var_name == "NOT_FOUND") {
        //     src.tmp_var_name = ID;
        //     src.type = INT_TY;
        //     src.val = 0;//default
        // } else {

        // }


        Var_Type src;
        // src.tmp_var_name = ID;
        // src.type = INT_TY;
        // src.val = 0;//default
        // symbol_table.add_symbol(src.tmp_var_name,src);
        src = symbol_table.lookup_var(ID);
        //auto iter=symbol_table.get_Lval(expr.name());
        //cout<<"111"<<endl;
        create_load(tar,src,current_bb);
        return tar;
    } else if (exp_type == BinOp_et) {
        auto operation=expr.name();

        auto expr1_addr=translate_expr(expr.children[0], symbol_table,current_bb);
        auto expr2_addr=translate_expr(expr.children[1], symbol_table,current_bb);
        Var_Type Lval_tmp1;
        Lval_tmp1 = get<Var_Type>(expr1_addr);
        if(get<int>(get<Var_Type>(expr1_addr).val)==999){
            //cout<<"QIUQIU"<<endl;
            Lval_tmp1.tmp_var_name = to_string(symbol_table.get_current_tbl_size());
            Lval_tmp1.type=INT_TY;
            //cout<<222<<endl;
            create_load(Lval_tmp1,get<Var_Type>(expr1_addr),current_bb);

            symbol_table.add_symbol(Lval_tmp1.tmp_var_name,Lval_tmp1);
        }
        Var_Type Lval_tmp2;
        Lval_tmp2 = get<Var_Type>(expr2_addr);
        if(get<int>(get<Var_Type>(expr2_addr).val)==999){
            //cout<<"QIUQIU"<<endl;
            Lval_tmp2.tmp_var_name = to_string(symbol_table.get_current_tbl_size());
            Lval_tmp2.type=INT_TY;
            create_load(Lval_tmp2,get<Var_Type>(expr2_addr),current_bb);

            symbol_table.add_symbol(Lval_tmp2.tmp_var_name,Lval_tmp2);
        }

        Var_Type BinOpRes;
        BinOpRes.tmp_var_name = to_string(symbol_table.get_current_tbl_size());
        BinOpRes.val = 0;//default
        BinOpRes.type = INT_TY;
        symbol_table.add_symbol(BinOpRes.tmp_var_name,BinOpRes);

        // for (auto i : symbol_table.Stack.top().Var_sym_tbl){
        //     cout << "first:" << i.first << endl;
        // }


        create_binary(operation,BinOpRes,Lval_tmp1,Lval_tmp2,current_bb);

        return BinOpRes;
        
        // Handle BinOp_et case
    } else if (exp_type == Unary_ARRAY_et||exp_type == Unary_BinOp_et||exp_type == Unary_ID_et) {
        //cout<<"In UNARY!!!"<<endl;
        string U_TY=get_unary_type(expr);
        auto zero_exp=create_constant(0, INT_TY);
        //auto expr1_value= get<Var_Type>(translate_expr(expr,symbol_table,current_bb));
        Var_Type expr1_value;
        //cout<<expr.name()<<endl;
        if(isDigitString(expr.name())){
            // expr1_value.tmp_var_name = expr.get_id();
            // expr1_value.type = INT_TY;
            // expr1_value.val = stoi(expr.get_id());
            expr1_value = get<Var_Type>(create_constant(stoi(expr.name()),INT_TY));
        }else{
            string ID = expr.name();
            std::regex pattern("LVal\\s*(.+)");
            std::smatch match;
            if (std::regex_search(ID, match, pattern)){
                ID = match[1];
            }
            //cout<<"FUFUFUF"<<endl;
            expr1_value= symbol_table.lookup_var(ID);
            Var_Type expr1_temp;
            expr1_temp.tmp_var_name = to_string(symbol_table.get_current_tbl_size());
            expr1_temp.type = INT_TY;
            expr1_temp.val = 0;//default
            symbol_table.add_symbol(expr1_temp.tmp_var_name,expr1_temp);
            create_load(expr1_temp, expr1_value,current_bb);
            expr1_value = expr1_temp;
            
        }
        
        Var_Type BinOpRes;
        BinOpRes.tmp_var_name = to_string(symbol_table.get_current_tbl_size());
        BinOpRes.val = 0;//default
        BinOpRes.type = INT_TY;
        symbol_table.add_symbol(BinOpRes.tmp_var_name,BinOpRes);
        //symbol_table.add_symbol(expr1_value.tmp_var_name,expr1_value);
        if(U_TY == "ADD"){
            create_binary("ADD",BinOpRes,get<Var_Type>(zero_exp),expr1_value,current_bb);

        }else if(U_TY == "SUB"){
            create_binary("SUB",BinOpRes,get<Var_Type>(zero_exp),expr1_value,current_bb);

        }else if(U_TY == "NOT"){
            create_binary("EQ",BinOpRes,get<Var_Type>(zero_exp),expr1_value,current_bb);

        }
        //cout<<"LALALAL"<<endl;
        expr1_value.tmp_var_name = "%"+to_string(symbol_table.get_current_tbl_size());//signify it is a unary.
        return BinOpRes;
        // Handle MINUS_et case
    } else if (exp_type == Call_et) {
        // Call ID, Args
        string ID = expr.type;
        Func_Type func = symbol_table.lookup_func(ID);
        func.tmp_arg_name.clear();
        func.args.clear();
        std::vector<ir_Type *> args_l;
        // node(ID) -> child(FuncRParams)->children(Arg, Arg, Arg, ...)
        if (expr.children_size() > 0){
            std::vector<Node> Args = expr.children[0].children;
            reverseVector(Args);
            for (auto arg : Args) {
                // string arg_string = arg->name();
                if (!startsWith(arg.type, "LVal")){
                    arg.ID = "FUNCTION";
                }
                ir_Type translated_arg = translate_expr(arg, symbol_table, current_bb);
                Var_Type Lval_tmp;
                //cout<<"SHITSHITSHIT!"<<endl;
                if(get<int>(get<Var_Type>(translated_arg).val)==999){
                    //cout<<"QIUQIU"<<endl;
                    Lval_tmp.tmp_var_name = to_string(symbol_table.get_current_tbl_size());
                    Lval_tmp.type=INT_TY;
                    //cout<<333;
                    
                    //cout<<"OVER"<<endl;
                    Type arg_type = Lval_tmp.type;
                    func.args.push_back(arg_type);
                    string arg_temp = Lval_tmp.tmp_var_name;
                    func.tmp_arg_name.push_back(arg_temp);
                    symbol_table.add_symbol(Lval_tmp.tmp_var_name,Lval_tmp);
                    create_load(Lval_tmp,get<Var_Type>(translated_arg),current_bb);
                }else{
                    //cout<<"WTFWTF"<<endl;
                    Type arg_type = get<Var_Type>(translated_arg).type;
                    func.args.push_back(arg_type);
                    string arg_temp = get<Var_Type>(translated_arg).tmp_var_name;
                    func.tmp_arg_name.push_back(arg_temp);
                }

            }
        }
        func.arg_num = func.args.size();
        string res_name = to_string(symbol_table.get_current_tbl_size());
        Var_Type res;
        res.type = func.return_type;
        res.val = func.return_val;
        res.tmp_var_name = res_name;
        symbol_table.add_symbol(res_name, res);

        create_function_call(func, ID, res_name, symbol_table, current_bb);
        return res;
    }
    else if (exp_type == ARRAY_et) {
        // ID[Idx1]..[IdxN]
        //cout<<"cur node"<<expr.name()<<endl;
        string ID1 = expr.get_id();
        //cout<<"ARRAY_et"<<endl;
        Var_Type &array = symbol_table.lookup_var(ID1);
        Type array_type = array.type;
        value array_value = array.val;
        int result_temp;
        Var_Type result;
        vector<string> idxs;
        string ids;
        for(auto iter = expr.children.begin();iter!=expr.children.end();iter++){
            string ID2 = iter->name();
            std::regex pattern("LVal\\s*([a-zA-Z]+)");
            std::smatch match;
            if (std::regex_search(ID2, match, pattern)){
                ID2 = match[1];
            }
            idxs.push_back(ID2);
            //cout<<"LALALA"<<endl;
            ids+=""+ID2+"";
        }
        string ID = expr.name();
        std::regex pattern("LVal\\s*(.+)");
        std::smatch match;
        if (std::regex_search(ID, match, pattern)){
            ID = match[1];
        }
        result.tmp_var_name = ID+ids;
        result.type = INT_TY;
        result.val = 999;//default for array, magical number 999 to signify
        symbol_table.add_symbol(result.tmp_var_name,result);
        //cout<<expr.name()<<endl;
        //cout<<"asdadafakfakfhiuhiwfhi"<<endl;
                        
        create_offset(result.tmp_var_name, ID1, idxs,symbol_table);//ASDASDA
        // Var_Type arr_tmp;
        // arr_tmp.tmp_var_name = symbol_table.get_current_tbl_size();
        // arr_tmp.type = INT_TY;
        // symbol_table.add_symbol(arr_tmp.tmp_var_name,arr_tmp);
        // create_load(arr_tmp,result,current_bb);
        //cout<<"????"<<endl;
        return result;

        // result.type = INT_TY;
        // if (array_type == ARRAY){
        //     int idx1 = atoi(expr.get(0)->name().c_str());
        //     result_temp = get<1>(array_value)[idx1];
        // }
        // else if(array_type ==LIST_2){
        //     int idx1 = atoi(expr.get(0)->name().c_str());            
        //     int idx2 = atoi(expr.get(1)->name().c_str());
        //     result_temp = get<2>(array_value)[idx1][idx2];
        // }
        // else if(array_type ==LIST_3){
        //     int idx1 = atoi(expr.get(0)->name().c_str());
        //     int idx2 = atoi(expr.get(1)->name().c_str());
        //     int idx3 = atoi(expr.get(2)->name().c_str());
        //     result_temp = get<3>(array_value)[idx1][idx2][idx3];
        // }
        // else if(array_type ==LIST_4){
        //     int idx1 = atoi(expr.get(0)->name().c_str());
        //     int idx2 = atoi(expr.get(1)->name().c_str());
        //     int idx3 = atoi(expr.get(2)->name().c_str());
        //     int idx4 = atoi(expr.get(3)->name().c_str());
        //     result_temp = get<4>(array_value)[idx1][idx2][idx3][idx4];
        // }
        // else if(array_type ==LIST_5){
        //     int idx1 = atoi(expr.get(0)->name().c_str());
        //     int idx2 = atoi(expr.get(1)->name().c_str());
        //     int idx3 = atoi(expr.get(2)->name().c_str());
        //     int idx4 = atoi(expr.get(3)->name().c_str());
        //     int idx5 = atoi(expr.get(4)->name().c_str());
        //     result_temp = get<5>(array_value)[idx1][idx2][idx3][idx4][idx5];
        // }
        // result.val = result_temp;
        // return result;
    }
}
void create_alloca(Var_Type var, int size, BasicBlock current_bb){
    auto res = new Operand(OPD_VARIABLE, var.tmp_var_name);
    auto size_ = new Operand(OPD_CONSTANT, size);
    auto inst = new Instruction(IR_ALLOCATION, *res, *size_);

    insert_instruction(*inst, current_bb);

    // Var_Type tmp;
    // tmp.tmp_var_name="tmp"+var.tmp_var_name;
    // tmp.type = var.type;
    // return tmp;

}//alloca 重要的是size和name--->be like %1...，type固定为 i32；size和name在vartype和value里分别找到

int calculate_array_size(Node node){
    //cout<<"INARRAYSIZE"<<node.name()<<endl;
    vector<int>& array_size = node.array_size;
    int size = 1;
    for(auto iter=array_size.begin();iter!=array_size.end();iter++){
        size *= *iter;
    }
    return size; 

}

Var_Type translate_unary(Node expr,Symbol_Table& symbol_table,BasicBlock current_bb){
    string U_TY=get_unary_type(expr);
        auto zero_exp=create_constant(0, INT_TY);
        //auto expr1_value= get<Var_Type>(translate_expr(expr,symbol_table,current_bb));
        Var_Type expr1_value;
        //cout<<expr.name()<<endl;
        if(isDigitString(expr.name())){
            // expr1_value.tmp_var_name = expr.get_id();
            // expr1_value.type = INT_TY;
            // expr1_value.val = stoi(expr.get_id());
            expr1_value = get<Var_Type>(create_constant(stoi(expr.name()),INT_TY));
        }else{
            string ID = expr.name();
            std::regex pattern("LVal\\s*(.+)");
            std::smatch match;
            if (std::regex_search(ID, match, pattern)){
                ID = match[1];
            }
            //cout<<"FUCKY OU"<<endl;
            expr1_value= symbol_table.lookup_var(ID);
        }
        
        Var_Type BinOpRes;
        BinOpRes.tmp_var_name = to_string(symbol_table.get_current_tbl_size());
        BinOpRes.val = 0;//default
        BinOpRes.type = INT_TY;
        symbol_table.add_symbol(BinOpRes.tmp_var_name,BinOpRes);
        //symbol_table.add_symbol(expr1_value.tmp_var_name,expr1_value);
        if(U_TY == "ADD"){
            create_binary("ADD",BinOpRes,get<Var_Type>(zero_exp),expr1_value,current_bb);

        }else if(U_TY == "SUB"){
            create_binary("SUB",BinOpRes,get<Var_Type>(zero_exp),expr1_value,current_bb);

        }else if(U_TY == "NOT"){
            create_binary("EQ",BinOpRes,get<Var_Type>(zero_exp),expr1_value,current_bb);

        }
        //cout<<"LALALAL"<<endl;
        expr1_value.tmp_var_name = "%"+to_string(symbol_table.get_current_tbl_size());//signify it is a unary.
        return BinOpRes;
}

int short_count = 0;
Var_Type translate_condition(Node expr, Symbol_Table& symbol_table, BasicBlock current_bb){
    BBs bbs = Func_BB_map[cur_Func];
    if (expr.type == "OR" || expr.type == "AND") {
        string rhs_label = "short_rhs_" + to_string(short_count);
        string se_label = "short_end_" + to_string(short_count);
        short_count++;
        // before branch rhs, end

        Node expr1 = expr.children[0];
        Var_Type val1 = translate_condition(expr1, symbol_table, current_bb);

        Var_Type short_val;
        short_val.tmp_var_name = "short_val_" + to_string(symbol_table.get_current_tbl_size()) + ".addr";
        short_val.type = INT_TY;
        short_val.val = 0;//default
        symbol_table.add_symbol(short_val.tmp_var_name,short_val);
        create_alloca(short_val, 1, current_bb);
        if (val1.type == NONE) {
            create_store(val1.tmp_var_name, short_val.tmp_var_name, current_bb, 2);
        } else {
            create_store(val1.tmp_var_name, short_val.tmp_var_name, current_bb);
        }

        // branch rhs, end
        if (expr.type == "AND") {
            create_branch(val1.tmp_var_name, rhs_label, se_label, current_bb);
        } else if (expr.type == "OR") {
            create_branch(val1.tmp_var_name, se_label, rhs_label, current_bb);
        }

        // short rhs
        vector<Instruction> short_rhs_inst;
        Operand rhs_label_op = Operand(OPD_VARIABLE, rhs_label);
        Instruction short_rhs_label = Instruction(IR_LABEL, rhs_label_op);
        short_rhs_inst.push_back(short_rhs_label);
        BasicBlock short_rhs_bb = BasicBlock(short_rhs_inst, rhs_label);
        bbs.push_back(short_rhs_bb);

        Node expr2 = expr.children[1];
        Var_Type val2 = get<Var_Type>(translate_expr(expr2, symbol_table, current_bb));
        if (val2.type == NONE) {
            create_store(val2.tmp_var_name, short_val.tmp_var_name, short_rhs_bb, 2);
        } else {
            create_store(val2.tmp_var_name, short_val.tmp_var_name, short_rhs_bb);
        }
        create_jump(se_label, short_rhs_bb);


        // short end
        vector<Instruction> short_end_inst;
        Operand se_label_op = Operand(OPD_VARIABLE, se_label);
        Instruction short_end_label = Instruction(IR_LABEL, se_label_op);
        short_end_inst.push_back(short_end_label);
        BasicBlock short_end_bb = BasicBlock(short_end_inst, se_label);
        bbs.push_back(short_end_bb);

        Var_Type short_end;
        short_end.tmp_var_name = to_string(symbol_table.get_current_tbl_size());
        short_end.type = INT_TY;
        short_end.val = 0;//default
        symbol_table.add_symbol(short_end.tmp_var_name,short_end);
        create_load(short_end, short_val, short_end_bb);
        return short_end;
    }
    else {
        ir_Type cond_value = translate_expr(expr, symbol_table, current_bb);
            
        Var_Type Lval_tmp1;
        Lval_tmp1 = get<Var_Type>(cond_value);
        if(get<int>(get<Var_Type>(cond_value).val)==999){
            //cout<<"QIUQIU"<<endl;
            Lval_tmp1.tmp_var_name = to_string(symbol_table.get_current_tbl_size());
            Lval_tmp1.type=INT_TY;
            create_load(Lval_tmp1,get<Var_Type>(cond_value),current_bb);
            symbol_table.add_symbol(Lval_tmp1.tmp_var_name,Lval_tmp1);
        }
        return Lval_tmp1;
    }
}

BasicBlock translate_stmt(Node stmt,Symbol_Table& symbol_table,BasicBlock current_bb){
    Expr_Stmt_type stmt_type=get_exprTpye_from_node(&stmt);
    if (stmt_type == VarDecl_st) {
        //cout << "stmt_type == VarDecl_st" << endl;
        BasicBlock entry_bb = Func_BB_map.find(cur_Func)->second[0];        

        string name = (stmt.children)[0].name();
        if(stmt.children_size()==1){
            Var_Type tmp;
            tmp.tmp_var_name = name;
            tmp.type = INT_TY;
            tmp.val= 0;
            SYM_TBL.add_symbol(name, tmp);
            

            create_alloca(tmp,1,current_bb);
        }else if(stmt.children_size()==2){
            Var_Type tmp;
            tmp.tmp_var_name = name;
            tmp.type = INT_TY;
            tmp.val= 0;

            SYM_TBL.add_symbol(name, tmp);
            

            create_alloca(tmp,1,current_bb);

            Var_Type res = get<Var_Type>(translate_expr(stmt.children[1],symbol_table,current_bb));

             if(get<int>(res.val)==999){
                Var_Type Lval_tmp;
                //cout<<"QIUQIU"<<endl;
                Lval_tmp.tmp_var_name = to_string(symbol_table.get_current_tbl_size());
                Lval_tmp.type=INT_TY;
                //cout<<444<<endl;
                create_load(Lval_tmp,res,current_bb);
                symbol_table.add_symbol(Lval_tmp.tmp_var_name,Lval_tmp);


                create_store(Lval_tmp.tmp_var_name,tmp.tmp_var_name,current_bb);
                
            }else{
                if (res.type == NONE) {
                    create_store(res.tmp_var_name,tmp.tmp_var_name,current_bb, 2);
                } else if (is_a_tmp_param(res)) {
                    create_store(res.tmp_var_name,tmp.tmp_var_name,current_bb, 1);
                } else {
                    create_store(res.tmp_var_name,tmp.tmp_var_name,current_bb);
                }
            }

            
        }        //auto var_type = SYM_TBL.lookup_var(name);
        //Var_Type alloca_instr = create_alloca(tmp,1,current_bb);
        //SYM_TBL.add_symbol(alloca_instr.tmp_var_name, alloca_instr);

        return current_bb;//??????why

        // Handle variable declaration statement
    } else if (stmt_type == VarDeclArray_st) {
        Type type = stmt.children[0].get_type();
        //cout<<"ARRAY: "<<type<<endl;
        // cout << "stmt_type == VarDeclArray_st" << endl;
        if (type == Type::ARRAY) {
            BasicBlock entry_bb = Func_BB_map.find(cur_Func)->second[0];        
                    //cout<<"here: "<<type<<endl;

            string name = (stmt.children)[0].name();
            Var_Type tmp;
            tmp.tmp_var_name = name;
            tmp.type = type;
            vector<int> tmp_;//default assignment
            tmp_ = stmt.children[0].array_size;//add this size
            tmp.val= tmp_;//revised to 999, seems no effets change or not
            SYM_TBL.add_symbol(name, tmp);
            //auto var_type = SYM_TBL.lookup_var(name);
            int size = calculate_array_size(stmt.children[0]);
                    //cout<<"herehrere: "<<type<<endl;

            create_alloca(tmp,size,current_bb);
            //cout<<"PASS ALLOCA"<<endl;
            //SYM_TBL.add_symbol(alloca_instr.tmp_var_name, alloca_instr);
            // 处理 ARRAY 类型的逻辑
        } else if (type == Type::LIST_2) {
            // 处理 LIST_2 类型的逻辑
            BasicBlock entry_bb = Func_BB_map.find(cur_Func)->second[0];        

            string name = (stmt.children)[0].name();
            Var_Type tmp;
            tmp.tmp_var_name = name;
            tmp.type = type;
            vector<int> tmp_;//default assignment
            tmp_ = stmt.children[0].array_size;//add this size
            tmp.val= tmp_;
            SYM_TBL.add_symbol(name, tmp);

            int size = calculate_array_size(stmt.children[0]);
            create_alloca(tmp,size,current_bb);
            //SYM_TBL.add_symbol(alloca_instr.tmp_var_name, alloca_instr);
        } else if (type == Type::LIST_3) {
            // 处理 LIST_3 类型的逻辑
            BasicBlock entry_bb = Func_BB_map.find(cur_Func)->second[0];        

            string name = (stmt.children)[0].name();
            Var_Type tmp;
            tmp.tmp_var_name = name;
            tmp.type = type;
            vector<int> tmp_;//default assignment
            tmp_ = stmt.children[0].array_size;//add this size
            tmp.val= tmp_;
            SYM_TBL.add_symbol(name, tmp);

            int size = calculate_array_size(stmt.children[0]);
            create_alloca(tmp,size,current_bb);
            //SYM_TBL.add_symbol(alloca_instr.tmp_var_name, alloca_instr);        
        } else if (type == Type::LIST_4) {
            // 处理 LIST_4 类型的逻辑
            BasicBlock entry_bb = Func_BB_map.find(cur_Func)->second[0];        

            string name = (stmt.children)[0].name();
            Var_Type tmp;
            tmp.tmp_var_name = name;
            tmp.type = type;
            vector<int> tmp_;//default assignment
            tmp_ = stmt.children[0].array_size;//add this size
            tmp.val= tmp_;
            SYM_TBL.add_symbol(name, tmp);

            int size = calculate_array_size(stmt.children[0]);
            create_alloca(tmp,size,current_bb);
            //SYM_TBL.add_symbol(alloca_instr.tmp_var_name, alloca_instr);
        } else if (type == Type::LIST_5) {
            // 处理 LIST_5 类型的逻辑
            BasicBlock entry_bb = Func_BB_map.find(cur_Func)->second[0];        

            string name = (stmt.children)[0].name();
            Var_Type tmp;
            tmp.tmp_var_name = name;
            tmp.type = type;
            vector<int> tmp_;//default assignment
            tmp_ = stmt.children[0].array_size;//add this size
            tmp.val= tmp_;
            SYM_TBL.add_symbol(name, tmp);

            int size = calculate_array_size(stmt.children[0]);
            create_alloca(tmp,size,current_bb);
            //SYM_TBL.add_symbol(alloca_instr.tmp_var_name, alloca_instr);
        } else {
            // 处理其他类型的逻辑
            assert(false);
        }
        return current_bb;

        // Handle variable declaration array statement
    } else if (stmt_type == Expr_st) {
        // cout << "stmt_type == Expr_st" << endl;

        // Handle expression statement
        if (stmt.children_size() != 0){
            stmt.children[0].ID = "FUNCTION";
            ir_Type res = translate_expr(stmt.children[0], symbol_table, current_bb);
        }
        else {
            ir_Type useless = translate_expr(stmt, symbol_table, current_bb);
        }
        return current_bb;
    } else if (stmt_type == Assign_st) {
        // cout << "stmt_type == Assign_st" << endl;

        // Handle assignment statement
        string ID = stmt.children[0].name();
        std::regex pattern("LVal\\s*(.+)");
        std::smatch match;
        if (std::regex_search(ID, match, pattern)){
            ID = match[1];
        }

        // for (auto i : symbol_table.Stack.top().Var_sym_tbl){
        //     cout << "first:" << i.first << endl;
        // }
        //cout<<"MAYBE"<<endl;
        Var_Type &var = symbol_table.lookup_var(ID);
        string addr_value;
        // cout << stmt.children[0].children_size() << endl;
        if (stmt.children[0].children_size() == 0){
            addr_value = var.tmp_var_name;
        } else {
            ir_Type res_ = translate_expr(stmt.children[0], symbol_table, current_bb);
            addr_value = get<Var_Type>(res_).tmp_var_name;
        }
        
        // 调用函数赋值
        if (!startsWith(stmt.children[1].type, "LVal")){
            stmt.children[1].ID = "FUNCTION";
        }
        
        // cout << "stmt_type == Assign_st1" << endl;
        // to do:判断类型，val or fun
        ir_Type val = translate_expr(stmt.children[1], symbol_table, current_bb); 

        Var_Type Lval_tmp1;
        Lval_tmp1 = get<Var_Type>(val);
        if(get<int>(get<Var_Type>(val).val)==999){
            //cout<<"QIUQIU"<<endl;
            Lval_tmp1.tmp_var_name = to_string(symbol_table.get_current_tbl_size());
            Lval_tmp1.type=INT_TY;
            create_load(Lval_tmp1,get<Var_Type>(val),current_bb);

            symbol_table.add_symbol(Lval_tmp1.tmp_var_name,Lval_tmp1);

            string result_value = Lval_tmp1.tmp_var_name;
 
            symbol_table.add_symbol(result_value, Lval_tmp1);
            create_store(result_value, addr_value, current_bb);
            
        }else{
            string result_value = get<Var_Type>(val).tmp_var_name;
            if (get<Var_Type>(val).type == NONE){
                create_store(result_value, addr_value, current_bb,2);
            }
            else {
                symbol_table.add_symbol(result_value, get<Var_Type>(val));
                create_store(result_value, addr_value, current_bb);
            }
        }

        // cout << "stmt_type == Assign_st2" << endl;
       

        return current_bb;  
    } else if (stmt_type == If_st) {
        // cout << "stmt_type == If_st" << endl;

        // Handle if statement
        BBs bbs = Func_BB_map[cur_Func];
        string tr_label = "if_true_" + to_string(bb_num);
        bb_num++;
        string ex_label = "if_exit_" + to_string(bb_num-1);
        bb_num++;

        // calculate condition expr in current basic block.
        Var_Type cond_value = translate_condition(stmt.children[0], symbol_table, current_bb);
        string cond = cond_value.tmp_var_name;
        create_branch(cond, tr_label, ex_label, Func_BB_map[cur_Func].back());
 

        // new basic block
        // new TRUE basic block
        vector<Instruction> true_inst;
        Operand tr_label_op = Operand(OPD_VARIABLE, tr_label);
        Instruction true_label = Instruction(IR_LABEL, tr_label_op);
        true_inst.push_back(true_label);
        BasicBlock true_bb = BasicBlock(true_inst, tr_label);
        bbs.push_back(true_bb);

        // translate true branch
        for (int i = 1; i < stmt.children_size(); i++) {
            Node true_stmt = *stmt.get(i);
            if (true_stmt.type == "Block") {
                BasicBlock true_bb_ = translate_stmt(true_stmt, symbol_table, true_bb);
                for (auto child : true_stmt.children) {
                    if (startsWith(child.type, "INT")) {
                        for (int i = 0; i < child.children_size(); i++) {
                            true_bb_ = translate_stmt(child.children[i], symbol_table, true_bb);
                        }
                    }
                    else true_bb_ = translate_stmt(child, symbol_table, true_bb);                
                }
            }
            else {
                BasicBlock true_bb_ = translate_stmt(true_stmt, symbol_table, true_bb);
            }
        }
        create_jump(ex_label, true_bb);

        // new EXIT basic block
        vector<Instruction> exit_inst;
        Operand ex_label_op = Operand(OPD_VARIABLE, ex_label);
        Instruction exit_label = Instruction(IR_LABEL, ex_label_op);
        exit_inst.push_back(exit_label);
        BasicBlock exit_bb = BasicBlock(exit_inst, ex_label);
        bbs.push_back(exit_bb);
        return exit_bb;

    } else if (stmt_type == IfElse_st) {
        // cout << "stmt_type == IfElse_st" << endl;

        // Handle if-else statement
        BBs bbs = Func_BB_map[cur_Func];
        string tr_label = "if_true_" + to_string(bb_num);
        bb_num++;
        string fl_label = "if_else_" + to_string(bb_num-1);
        bb_num++;
        string ex_label = "if_exit_" + to_string(bb_num-2);
        bb_num++;

        // calculate condition expr in current basic block.
        Var_Type cond_value = translate_condition(stmt.children[0], symbol_table, current_bb);
        string cond = cond_value.tmp_var_name;
        create_branch(cond, tr_label, fl_label, Func_BB_map[cur_Func].back());
 

        // new TRUE basic block
        vector<Instruction> true_inst;
        Operand tr_label_op = Operand(OPD_VARIABLE, tr_label);
        Instruction true_label = Instruction(IR_LABEL, tr_label_op);
        true_inst.push_back(true_label);
        BasicBlock true_bb = BasicBlock(true_inst, tr_label);
        bbs.push_back(true_bb);  

        Node true_stmts = stmt.children[1];
        if (true_stmts.type == "Block") {
            BasicBlock true_bb_ = translate_stmt(true_stmts, symbol_table, true_bb);
            for (int i = 0; i < true_stmts.children_size(); i++) {
                Node true_stmt = true_stmts.children[i];
                if (startsWith(true_stmt.type, "INT")) {
                    for (int i = 0; i < true_stmt.children_size(); i++) {
                        true_bb_ = translate_stmt(true_stmt.children[i], symbol_table, true_bb);
                    }
                }
                else true_bb_ = translate_stmt(true_stmt, symbol_table, true_bb);
            }
        }
        else {
            BasicBlock true_bb_ = translate_stmt(true_stmts, symbol_table, true_bb);
        }
        create_jump(ex_label, true_bb);
        //cout << "here" << endl;
        // new FALSE basic block
        vector<Instruction> false_inst;
        Operand fl_label_op = Operand(OPD_VARIABLE, fl_label);
        Instruction false_label = Instruction(IR_LABEL, fl_label_op);
        false_inst.push_back(false_label);
        BasicBlock false_bb = BasicBlock(false_inst, fl_label);
        bbs.push_back(false_bb); 

        Node false_stmts = stmt.children[2];
        if (false_stmts.type == "Block") {
            BasicBlock false_bb_ = translate_stmt(false_stmts, symbol_table, false_bb);
            for (int i = 0; i < false_stmts.children_size(); i++) {
                Node false_stmt = false_stmts.children[i];
                if (startsWith(false_stmt.type, "INT")) {
                    for (int i = 0; i < false_stmt.children_size(); i++) {
                        false_bb_ = translate_stmt(false_stmt.children[i], symbol_table, false_bb);
                    }
                }
                else false_bb_ = translate_stmt(false_stmt, symbol_table, false_bb);
            }
        }
        else {
            BasicBlock false_bb_ = translate_stmt(false_stmts, symbol_table, false_bb);
        }
        create_jump(ex_label, false_bb); 

        // new EXIT basic block
        vector<Instruction> exit_inst;
        Operand ex_label_op = Operand(OPD_VARIABLE, ex_label);
        Instruction exit_label = Instruction(IR_LABEL, ex_label_op);
        exit_inst.push_back(exit_label);
        BasicBlock exit_bb = BasicBlock(exit_inst, ex_label);
        bbs.push_back(exit_bb);
        

        return exit_bb;
    } else if (stmt_type == While_st) {
        // cout << "stmt_type == While_st" << endl;

        // Handle while statement
        BBs bbs = Func_BB_map[cur_Func];
        string et_label = "while_cond_" + to_string(bb_num);
        bb_num++;
        string bd_label = "while_body_" + to_string(bb_num-1);
        bb_num++;
        string ex_label = "while_exit_" + to_string(bb_num-2);
        bb_num++;

        create_jump(et_label, current_bb);

        // new ENTRY basic block
        vector<Instruction> entry_inst;
        Operand et_label_op = Operand(OPD_VARIABLE, et_label);
        Instruction entry_label = Instruction(IR_LABEL, et_label_op);
        entry_inst.push_back(entry_label);
        BasicBlock entry_bb = BasicBlock(entry_inst, et_label);
        bbs.push_back(entry_bb);

        // entry block of While should be separated.

        Var_Type cond_value = translate_condition(stmt.children[0], symbol_table, current_bb);
        string cond = cond_value.tmp_var_name;
        create_branch(cond, bd_label, ex_label, Func_BB_map[cur_Func].back());


        // new BODY basic block
        vector<Instruction> body_inst;
        Operand bd_label_op = Operand(OPD_VARIABLE, bd_label);
        Instruction body_label = Instruction(IR_LABEL, bd_label_op);
        body_inst.push_back(body_label);
        BasicBlock body_bb = BasicBlock(body_inst, bd_label);
        bbs.push_back(body_bb);  

        Node true_stmts = stmt.children[1];
        if (true_stmts.type == "Block") {
            BasicBlock true_bb_ = translate_stmt(true_stmts, symbol_table, body_bb);
            for (int i = 0; i < true_stmts.children_size(); i++) {
                Node true_stmt = true_stmts.children[i];
                if (startsWith(true_stmt.type, "INT")) {
                    for (int i = 0; i < true_stmt.children_size(); i++) {
                        true_bb_ = translate_stmt(true_stmt.children[i], symbol_table, body_bb);
                    }
                }
                else true_bb_ = translate_stmt(true_stmt, symbol_table, body_bb);
            }
        }
        else {
            BasicBlock true_bb_ = translate_stmt(true_stmts, symbol_table, body_bb);
        }
        create_jump(et_label, entry_bb);

        // new EXIT basic block
        vector<Instruction> exit_inst;
        Operand ex_label_op = Operand(OPD_VARIABLE, ex_label);
        Instruction exit_label = Instruction(IR_LABEL, ex_label_op);
        exit_inst.push_back(exit_label);
        BasicBlock exit_bb = BasicBlock(exit_inst, ex_label);
        bbs.push_back(exit_bb);
        return exit_bb;
    } else if (stmt_type == Return_st) {
        // cout << "stmt_type == Return_st" << endl;
        // Handle return statement
        BasicBlock return_bb = Func_BB_map.find(cur_Func)->second.back();
        Var_Type return_addr;
        return_addr.tmp_var_name = "return.addr";
        return_addr.type = INT_TY;
        return_addr.val = 0;//default
        // create_alloca(return_addr,1,current_bb);
        symbol_table.add_symbol(return_addr.tmp_var_name, return_addr);
        auto return_value = translate_expr(stmt.children[0],symbol_table,current_bb);

        Var_Type Lval_tmp1;
        Lval_tmp1 = get<Var_Type>(return_value);
        if(get<int>(get<Var_Type>(return_value).val)==999){
            //cout<<"QIUQIU"<<endl;
            Lval_tmp1.tmp_var_name = to_string(symbol_table.get_current_tbl_size());
            Lval_tmp1.type=INT_TY;
            create_load(Lval_tmp1,get<Var_Type>(return_value),current_bb);

            symbol_table.add_symbol(Lval_tmp1.tmp_var_name,Lval_tmp1);
            create_store(Lval_tmp1.tmp_var_name, return_addr.tmp_var_name, current_bb);
        }else{
            if (get<Var_Type>(return_value).type == NONE){
                create_store(get<Var_Type>(return_value).tmp_var_name, return_addr.tmp_var_name, current_bb, 2);
            }
            else create_store(get<Var_Type>(return_value).tmp_var_name, return_addr.tmp_var_name, current_bb);
        }


        create_ret(return_addr.tmp_var_name, symbol_table, current_bb);
        vector<Instruction> empty;
        BasicBlock end_block = BasicBlock(empty, "EOF");
        return end_block;
    } else if (stmt_type == FucDef_est) {
        // cout << "stmt_type == FucDef_est" << endl;
        // Handle function definition statement
        string func_name = stmt.name();
        BBs BBs_;
        vector<Instruction> insts;
        string name = "b" + to_string(bb_num++);
        auto label_ = new Operand(OPD_VARIABLE, name);

        
        std::regex pattern("FucDef (.*?)(INT|VOID)");//fname
        std::smatch matches;
        string tmp = stmt.name();
        string name_;
        string ret_type_;
        if (std::regex_search(tmp, matches, pattern)) {
            name_ = matches[1].str() ;
            ret_type_ = matches[2].str();

        }//fname!

        auto fname = new Operand(OPD_VARIABLE, name_);
        auto ret_type = new Operand(OPD_VARIABLE, ret_type_);
        vector<Var_Type> args;
        if (stmt.children[0].type == "FuncFParams"){
            Node params = stmt.children[0];
            vector<Node> params_ = params.children;
            reverseVector(params_);
            for(auto iter = params_.begin();iter!=params_.end();iter++){
                Var_Type tmp;
                tmp.tmp_var_name = iter->name();
                int childrensize=iter->children_size();
                if(childrensize==0)
                    tmp.type = INT_TY;
                else
                    tmp.type = ARRAY;//
                tmp.val = 0;//default
                args.push_back(tmp);
                symbol_table.add_symbol(tmp.tmp_var_name,tmp);
            }
        }
        else {
            Var_Type tmp;
            tmp.tmp_var_name = "none";
            tmp.type = NONE;
            tmp.val = 0;//default
            args.push_back(tmp);
        }
        auto args_ = new Operand(OPD_ARGS, args);
        auto func_def_inst = new Instruction(IR_FUNCDEF, *fname,*args_,*ret_type);
        insert_instruction(*func_def_inst, current_bb);
        Func_Type ftmp;
        ftmp.args =  vector<Type>{};
        ftmp.arg_num = 0;
        ftmp.return_type = INT_TY;
        ftmp.return_val = 0;

        auto inst = new Instruction(IR_LABEL,*label_);
        insts.push_back(*inst);
        BasicBlock bb = BasicBlock(insts, name);

        for(auto iter = args.begin();iter!=args.end();iter++){
            if(iter->type == INT_TY){
                Var_Type tmp;
                tmp.tmp_var_name = iter->tmp_var_name+".addr";
                create_alloca(tmp,1,bb);
                symbol_table.add_symbol(tmp.tmp_var_name,tmp);
                //cout<<111<<endl;
                create_store(iter->tmp_var_name,tmp.tmp_var_name,bb,1);
            }else{
                //create_alloca(*iter,calculate_array_size())
            }
                
        }
        
        BBs_.push_back(bb);
        Var_Type return_addr;
        return_addr.tmp_var_name = "return.addr";
        return_addr.type = INT_TY;
        return_addr.val = 0;//default
        create_alloca(return_addr,1, bb);

        symbol_table.add_symbol(name_,ftmp);
        cur_Func = name_;
        cur_params = args;
        Func_BB_map.insert(pair(name_, BBs_));
        return bb;
    } else if (stmt_type == Block_st) {
        auto st = symbol_table.Stack.top();
        SYM_TBL.Stack.push(st);
        return current_bb;
    }
    //  else {
    //     // Handle other cases or error
    //     assert(0);
    // }
    return current_bb;
}

bool is_a_tmp_param(Var_Type var){
    for(auto iter = cur_params.begin();iter!=cur_params.end();iter++){
        if(iter->tmp_var_name == var.tmp_var_name){
            return true;
        }
    }
    return false;

}

void init_libs() {
// fn @putint(#x: i32) -> ();
    cout << "fn @putint(#x: i32) -> ();" << endl << endl;
    Func_Type ftmp1;
    ftmp1.args =  vector<Type>{INT_TY};
    ftmp1.arg_num = 1;
    ftmp1.return_type = VOID_TY;
    ftmp1.return_val = 0;
    SYM_TBL.add_symbol("putint", ftmp1);

// fn @putch(#x: i32) -> ();
    cout << "fn @putch(#x: i32) -> ();" << endl << endl;
    Func_Type ftmp2;
    ftmp2.args =  vector<Type>{INT_TY};
    ftmp2.arg_num = 1;
    ftmp2.return_type = VOID_TY;
    ftmp2.return_val = 0;
    SYM_TBL.add_symbol("putch", ftmp2);

// fn @putarray(#n: i32, #arr: i32*) -> ();
    cout << "fn @putarray(#n: i32, #arr: i32*) -> ();" << endl << endl;
    Func_Type ftmp3;
    ftmp3.args =  vector<Type>{INT_TY, ARRAY};
    ftmp3.arg_num = 21;
    ftmp3.return_type = VOID_TY;
    ftmp3.return_val = 0;
    SYM_TBL.add_symbol("putarray", ftmp3);

// fn @getint() -> i32;
    cout << "fn @getint() -> i32;" << endl << endl;
    Func_Type ftmp4;
    ftmp4.args =  vector<Type>{};
    ftmp4.arg_num = 0;
    ftmp4.return_type = INT_TY;
    ftmp4.return_val = 0;
    SYM_TBL.add_symbol("getint", ftmp4);

// fn @getch() -> i32;
    cout << "fn @getch() -> i32;" << endl << endl;
    Func_Type ftmp5;
    ftmp5.args =  vector<Type>{};
    ftmp5.arg_num = 0;
    ftmp5.return_type = INT_TY;
    ftmp5.return_val = 0;
    SYM_TBL.add_symbol("getch", ftmp5);

// fn @getarray(#n: i32, #arr: i32*) -> ();
    cout << "fn @getarray(#n: i32, #arr: i32*) -> ();" << endl << endl;
    Func_Type ftmp6;
    ftmp6.args =  vector<Type>{INT_TY, ARRAY};
    ftmp6.arg_num = 2;
    ftmp6.return_type = VOID_TY;
    ftmp6.return_val = 0;
    SYM_TBL.add_symbol("getarray", ftmp6);
}

void handle_global(Node node){
    Expr_Stmt_type node_type = get_exprTpye_from_node(&node);
    auto stmt_type = node_type;
    auto stmt = node;
    if (stmt_type == VarDecl_st) {
        
        //cout << "stmt_type == VarDecl_st" << endl;
        int num = stmt.children_size();
        if(num == 1){
            // cout<<"HEREhere1"<<endl;

            string name = (stmt.children)[0].name();
            Var_Type tmp;
            tmp.tmp_var_name = name;
            tmp.type = INT_TY;
            tmp.val= 0;
            tmp.is_GLOBAL = true;
            //cout<<"TMP "<<tmp.is_GLOBAL<<endl;
            //cout<<"GLOBAL DECL "<<tmp.tmp_var_name<<endl;
            SYM_TBL.add_symbol(name, tmp);
            //cout<<"WFT"<<SYM_TBL.lookup_var(name).is_GLOBAL<<endl;
            GLOBALs.insert(name);
            //create_alloca(tmp,1,current_bb);
            cout<<"@"<<name<<": "<<"region i32, "<<1<<endl;
        } else if (num == 2){
            // cout<<"HEREhere2"<<endl;

            string name = (stmt.children)[0].name();
            Var_Type tmp;
            tmp.tmp_var_name = name;
            tmp.type = INT_TY;
            tmp.val= 0;
            tmp.is_GLOBAL = true;
            SYM_TBL.add_symbol(name, tmp);
            GLOBALs.insert(name);
            cout<<"@"<<name<<": "<<"region i32, "<<1<<endl;

            //create_alloca(tmp,1,current_bb);

            string name1 = "0";//(stmt.children)[1].name();//get the constant value to init assign
            Var_Type tmp_;
            tmp_.tmp_var_name = name1;
            tmp_.type = INT_TY;
            tmp_.val= stoi(name1);

            tmp.val=tmp_.val;
            //create_store(name1,name,current_bb);

        }
    }else{//array global declaration
        Type type = stmt.children[0].get_type();
        //cout<<"type: "<<type<<endl;
        //cout << "stmt_type == VarDeclArray_st" << endl;
        if (type == Type::ARRAY) {
            //cout<<"LALALALAALAL1"<<endl;

            //cout<<"LALALALAALAL2"<<endl;
            string name = (stmt.children)[0].name();
            //cout<<"QAQAQ"<<endl;
            Var_Type tmp;
            tmp.tmp_var_name = name;
            tmp.type = type;
            vector<int> tmp_;//default assignment
            tmp.val= stmt.children[0].array_size;//maigc number to signify array
            tmp.is_GLOBAL = true;
            SYM_TBL.add_symbol(name, tmp);
            //GLOBALs.insert(name);
            //auto var_type = SYM_TBL.lookup_var(name);
            //cout<<"AREUOK"<<" "<<name<<endl;
            int size = calculate_array_size(stmt.children[0]);
            cout<<"@"<<name<<": "<<"region i32, "<<size<<endl;            
            //create_alloca(tmp,size,current_bb);
            //SYM_TBL.add_symbol(alloca_instr.tmp_var_name, alloca_instr);
            // 处理 ARRAY 类型的逻辑
            //cout<<"SAKJDASKJFASKJFAJ"<<endl;
        } else if (type == Type::LIST_2) {
            // 处理 LIST_2 类型的逻辑
            //cout<<"In LIST_2"<<endl;
            //BasicBlock entry_bb = Func_BB_map.find(cur_Func)->second[0];        

            string name = (stmt.children)[0].name();
            Var_Type tmp;
            tmp.tmp_var_name = name;
            tmp.type = type;
            vector<vector<int>> tmp_;//default assignment
            tmp.val= stmt.children[0].array_size;
            tmp.is_GLOBAL = true;
            SYM_TBL.add_symbol(name, tmp);
            GLOBALs.insert(name);
            //cout<<"here"<<endl;
            int size = calculate_array_size(stmt.children[0]);
            cout<<"@"<<name<<": "<<"region i32, "<<size<<endl;            
            //SYM_TBL.add_symbol(alloca_instr.tmp_var_name, alloca_instr);
        } else if (type == Type::LIST_3) {
            // 处理 LIST_3 类型的逻辑
            //BasicBlock entry_bb = Func_BB_map.find(cur_Func)->second[0];        

            string name = (stmt.children)[0].name();
            Var_Type tmp;
            tmp.tmp_var_name = name;
            tmp.type = type;
            vector<vector<vector<int>>> tmp_;//default assignment
            tmp.val= stmt.children[0].array_size;
            tmp.is_GLOBAL = true;
            SYM_TBL.add_symbol(name, tmp);
            GLOBALs.insert(name);
            int size = calculate_array_size(stmt.children[0]);
            cout<<"@"<<name<<": "<<"region i32, "<<size<<endl;            
            //SYM_TBL.add_symbol(alloca_instr.tmp_var_name, alloca_instr);        
        } else if (type == Type::LIST_4) {
            // 处理 LIST_4 类型的逻辑
            //BasicBlock entry_bb = Func_BB_map.find(cur_Func)->second[0];        

            string name = (stmt.children)[0].name();
            Var_Type tmp;
            tmp.tmp_var_name = name;
            tmp.type = type;
            vector<vector<vector<vector<int>>>> tmp_;//default assignment
            tmp.val= stmt.children[0].array_size;
            tmp.is_GLOBAL = true;
            SYM_TBL.add_symbol(name, tmp);
            GLOBALs.insert(name);
            int size = calculate_array_size(stmt.children[0]);
            cout<<"@"<<name<<": "<<"region i32, "<<size<<endl;            
            //SYM_TBL.add_symbol(alloca_instr.tmp_var_name, alloca_instr);
        } else if (type == Type::LIST_5) {
            // 处理 LIST_5 类型的逻辑
            //BasicBlock entry_bb = Func_BB_map.find(cur_Func)->second[0];        

            string name = (stmt.children)[0].name();
            Var_Type tmp;
            tmp.tmp_var_name = name;
            tmp.type = type;
            vector<vector<vector<vector<vector<int>>>>> tmp_;//default assignment
            tmp.val= stmt.children[0].array_size;
            tmp.is_GLOBAL = true;
            SYM_TBL.add_symbol(name, tmp);
            GLOBALs.insert(name);
            int size = calculate_array_size(stmt.children[0]);
            cout<<"@"<<name<<": "<<"region i32, "<<size<<endl;            
            //SYM_TBL.add_symbol(alloca_instr.tmp_var_name, alloca_instr);
        } else {
            // 处理其他类型的逻辑
            assert(false);
        }

    }
}

void create_func_exit(Symbol_Table& symbol_table) {
    Instruction inst_jmp2 = Instruction(IR_JUMP, Operand(OPD_VARIABLE, "exit"));


    Instruction inst_label_exit = Instruction(IR_LABEL, Operand(OPD_VARIABLE, "exit"));
    vector<Instruction> label2 = {inst_label_exit};
    BasicBlock exit = BasicBlock(label2, "exit");
    
    Var_Type tar;
    tar.tmp_var_name = to_string(symbol_table.get_current_tbl_size());
    tar.type = INT_TY;
    tar.val = 0;//default
    symbol_table.add_symbol(tar.tmp_var_name,tar);

    Var_Type return_addr = symbol_table.lookup_var("return.addr");
    create_load(tar, return_addr, exit);

    Operand op1 = Operand(OPD_VARIABLE, tar.tmp_var_name);
    Instruction new_inst = Instruction(IR_RETURN, op1);
    exit.inst_list.push_back(new_inst);

    Func_BB_map[cur_Func].push_back(exit);
}


bool once = true;
void traverseTree(Node node) {
    Expr_Stmt_type node_type = get_exprTpye_from_node(&node);
    // stmts
    if (node_type > 8 && node_type <= 16){
        if(cur_Func!=""){
            //cout<<"HERE"<<endl;
            
            BasicBlock current_bb = Func_BB_map.find(cur_Func)->second.back();
             //cout<<"HEREhere"<<endl;
            BasicBlock bb = translate_stmt(node, SYM_TBL, current_bb);
        }else{
            handle_global(node);
        }
    }
    else if (node_type == 8){
        if(once){init_libs();once=false;}
        BasicBlock current_bb = BasicBlock(std::vector<Instruction>(), "bb" + std::to_string(bb_num));
        bb_num++;
        BasicBlock bb = translate_stmt(node, SYM_TBL, current_bb);
        //cout<<"!@!@!@!@"<<endl;
        bool first = true;
        for (auto child : node.children) {
            //cout << "for (auto child : node.children)" << endl;
            if(node.children_size()!=1){
                if(first) {first = false;continue;}//skip the first child of fucDef which is PArams.
            }
            
            traverseTree(child);
            //cout<<"after"<<endl;
        }
        create_func_exit(SYM_TBL);
        // cout << "func end!!!" << endl;
    }
    else if (node_type == Block_st){
        //cout<<"In block"<<endl;
        BasicBlock current_bb = Func_BB_map.find(cur_Func)->second.back();
        BasicBlock bb = translate_stmt(node, SYM_TBL, current_bb);
        for (auto child : node.children) {
            traverseTree(child);
        }
    }
    // else if (node_type >= 0 && node_type <= 7){
    //     current_bb = Func_BB_map.find(cur_Func)->second.back();
    //     translate_exp(node, SYM_TBL, current_bb);
    //     for(auto inst : bb.inst_list) {
    //         inst.print();
    //     }
    //     for (auto child : node.children) {
    //         cout << "for (auto child : node.children)" << endl;
    //         traverseTree(child);
    //     }
    // }
    else {
        for (auto child : node.children) {
            traverseTree(child);
        }
    }

}