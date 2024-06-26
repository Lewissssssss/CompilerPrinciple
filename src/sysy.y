%{
#include <stdio.h>
#include <ast/ast.h>
#include <string>
#include <iostream>
using namespace std;
void yyerror(const char *s);
extern int yylex(void);
extern Node root;
extern TABLE_LISTS tables;
map<string,Type> temp_type_map;
vector<int> array_length;
bool is_func = false;
string func_name;
#define YYSTYPE Node*
%}

/// types


%token INT_CONST
%token ADD SUB MUL DIV MOD NOT 
%token LT GT LE GE EQ NE
%token ASSIGN
%token SEMI ";"
%token COLON ":"
%token COMMA "," 
%token LC "{" 
%token RC "}"
%token LB "["
%token RB "]"
%token LP "("
%token RP ")"
%token CONST 
%token IF 
%token ELSE 
%token WHILE 
%token BREAK 
%token RETURN 
%token CONTINUE 
%token AND OR
%token INT
%token ID
%token VOID


%start CompUnit


%left ADD SUB
%left MUL DIV MOD 
%right ASSIGN NOT


%%
CompUnit : Decl {root.add(*$1); $1->print(1);delete $1 ;}
        | FuncDef {root.add(*$1); $1->print(1);delete $1 ;}
        | CompUnit Decl{  root.add(*$2);$2->print(1); delete $2;}
        | CompUnit FuncDef{ root.add(*$2);$2->print(1); delete $2;}

Decl : VarDecl { $$ = $1;}

VarDecl : INT VarDef VerDefGroup SEMI {$$ = $3; $$->add(*$2); $$->rename("INT VarDecl");
                }                        

VerDefGroup : VerDefGroup COMMA VarDef {$$ = $1; $$->add(*$3);delete $3;}
           |  {$$ = new Node("VerDefGroup"); }

VarDef : ID ConstGroup ASSIGN InitVal {$$ = new Node("VerDef");$$->add(*$1);$$->add(*$3);
                if(tables.get_var_in_scope($1->name())==NONE){
                        Type ty;
                        vector<int> array_length;
                        array_length.clear();
                        cout << "VarDef_param: " << $1->name()<< " " << $2->children_size() << endl;
                        for(int i=0;i<$2->children_size();i++)
                                array_length.push_back(atoi($2->get(i)->name().c_str()));
                                $$->get(0)->array_size = array_length;//.push_back(atoi($2->get(i)->name().c_str()));
                        if($2->children_size()==0){
                                ty = INT_TY;
                        }else if( $2->children_size()==1){
                                $$->get(0)->set_type(ARRAY);
                                ty = ARRAY;
                        }
                        else if($2->children_size()==2){
                                $$->get(0)->set_type(LIST_2);
                                ty = LIST_2;
                        } else if($2->children_size()==3){
                                $$->get(0)->set_type(LIST_3);
                                ty = LIST_3;
                        } else if($2->children_size()==4){
                                $$->get(0)->set_type(LIST_4);
                                ty = LIST_4;
                        } else {
                                $$->get(0)->set_type(LIST_5);
                                ty = LIST_5;
                        } 
                        tables.add_var($1->name(),ty);
                        tables.set_var_array($1->name(),array_length);
                }
                else
                        {
                        cout << "error: redefined variable: "<< $1->name() << endl ;return 1;
                        }
        }
        |ID ConstGroup {$$ = new Node("VerDef");$$->add(*$1);
                if(tables.get_var_in_scope($1->name())==NONE){
                        Type ty;
                        cout << "VarDef_param: " << $1->name()<< " " << $2->children_size() << endl;
                        array_length.clear();
                        for(int i=0;i<$2->children_size();i++)
                                array_length.push_back(atoi($2->get(i)->name().c_str()));
                                $$->get(0)->array_size = array_length;//.push_back(atoi($2->get(i)->name().c_str()));
                        if($2->children_size()==0){
                                ty = INT_TY;
                        }else if( $2->children_size()==1){
                                $$->get(0)->set_type(ARRAY);
                                ty = ARRAY;}
                        else if($2->children_size()==2){
                                $$->get(0)->set_type(LIST_2);
                                ty = LIST_2;
                        } else if($2->children_size()==3){
                                $$->get(0)->set_type(LIST_3);
                                ty = LIST_3;
                        } else if($2->children_size()==4){
                                $$->get(0)->set_type(LIST_4);
                                ty = LIST_4;
                        } else {
                                
                                ty = LIST_5;
                        }
                        tables.add_var($1->name(),ty);
                        tables.set_var_array($1->name(),array_length);

                }
                else{
                        // print_table(tables);

                        cout << "error: redefined variable: "<< $1->name() << endl ;return 1;}
        }
ConstGroup :{$$ = new Node("ConstGroup");}  
        |  LB INT_CONST RB ConstGroup {$$ = $4; $$->add(*$2);}

InitVal : Exp {$$ = $1;
        if($1->get_type()!=INT_TY){
                cout << "wrong type for Initval" << endl;return 1;
                
        }
        }

FuncDef : FuncDefPre Block {$$ = $1; $$->add(*$2); }


FuncDefPre : INT ID LP RP{printf("FuncDef\n"); $$ = new Node("FucDef "+$2->name() + "INT" );
        if(tables.find_func($2->name())){
                cout << "error: redefined function" << endl;return 1;
                
        }
        else{
                vector<Type> params;
                params.push_back(INT_TY);
                tables.add_func($2->name(),params);
                is_func = true;
                func_name = $2->name();
        } 
        } 
        | INT ID LP FuncFParams RP{$$ = new Node("FucDef "+$2->name() +"INT" );$$->add(*$4);
        if(tables.find_func($2->name())){
                cout << "error: redefined function" << endl;return 1;
                
        }
        else{
                vector<Type> params;
                vector<vector<int>> func_array_length;
                params.push_back(INT_TY);
                for(int i=0;i<$4->children_size();i++){
                        string name = $4->get(i)->name();
                        Type ty = temp_type_map[name];
                        params.push_back(ty);
                        Node* ptr = $4->get(i); //得到funcParam
                        if(ptr->children_size()!=0){ //有constant group，即是数组
                                ptr = ptr->get(0);
                                vector<int> array_length;
                                // array_length.push_back(i);
                                for(int i=0;i<ptr->children_size();i++){
                                     array_length.push_back(atoi(ptr->get(i)->name().c_str()));
                                     $$->get(i)->array_size = array_length;//.push_back(atoi(ptr->get(j)->name().c_str()));
                                }
                                func_array_length.push_back(array_length);
                        }
                }      
                tables.add_func($2->name(),params);
                tables.set_func_array($2->name(),func_array_length);
                is_func = true;
                func_name = $2->name();
        }
        }
        | VOID ID LP RP {$$ = new Node("FucDef "+$2->name() + "VOID" );
        if(tables.find_func($2->name())){
                cout << "error: redefined function" << endl;return 1;
                
        }
        else{
                vector<Type> params;
                params.push_back(VOID_TY);
                tables.add_func($2->name(),params);
                is_func = true;
                func_name = $2->name();
        }
        }
        | VOID ID LP FuncFParams RP{$$ = new Node("FucDef "+$2->name() + "VOID" );$$->add(*$4);
        if(tables.find_func($2->name())){
                cout << "error: redefined function" << endl;return 1;
                
        }
        else{
                vector<Type> params;
                vector<vector<int>> func_array_length;
                params.push_back(VOID_TY);
                for(int i=0;i<$4->children_size();i++){
                        string name = $4->get(i)->name();
                        Type ty = temp_type_map[name];
                        params.push_back(ty);
                        Node* ptr = $4->get(i); //得到funcParam
                        if(ptr->children_size()!=0){ //有constant group，即是数组
                                ptr = ptr->get(0);
                                vector<int> array_length;
                                for(int i=0;i<ptr->children_size();i++){
                                     array_length.push_back(atoi(ptr->get(i)->name().c_str()));
                                     $$->get(i)->array_size.push_back(atoi($5->get(i)->name().c_str()));
                                }
                                func_array_length.push_back(array_length);
                        }
                }     
                tables.add_func($2->name(),params);         
                tables.set_func_array($2->name(),func_array_length);
                is_func = true;
                func_name = $2->name();
        }
        
        }


FuncFParams : FuncFParam { $$ = new Node("FuncFParams"); $$->add(*$1); } 
        | FuncFParam  COMMA  FuncFParams { $$ = $3; $$->add(*$1); }


FuncFParam : INT ID { $$ = new Node($2->name());  
                temp_type_map[$2->name()] = INT_TY;
        }
        | INT ID LB RB ConstGroup{ $$ = new Node($2->name()); $$->add(*$5);
                
                for(int i=0;i<$5->children_size();i++){
                        array_length.push_back(atoi($5->get(i)->name().c_str()));
                        $$->get(0)->array_size.push_back(atoi($5->get(i)->name().c_str()));
                }
                if($5->children_size()==0){
                        $$->get(0)->set_type(ARRAY);
                        temp_type_map[$2->name()] = ARRAY;
                }
                else if($5->children_size()==1){        
                        $$->get(0)->set_type(LIST_2);
                        temp_type_map[$2->name()] = LIST_2;
                }else if($5->children_size()==2){     
                        $$->get(0)->set_type(LIST_3);  
                        temp_type_map[$2->name()] = LIST_3;
                }else if($5->children_size()==3){ 
                        $$->get(0)->set_type(LIST_4);       
                        temp_type_map[$2->name()] = LIST_4;
                }else{
                        $$->get(0)->set_type(LIST_5);
                        temp_type_map[$2->name()] = LIST_5;
                }
        }

LC_B : LC {tables.BEGIN_SCOPE(); 
                for(auto &[j,k]:temp_type_map){
                        tables.add_var(j,k);
                }
                temp_type_map.clear();  
                if(is_func){
                        is_func = false;
                        Type ty = tables.get_func(func_name)[0];
                        tables.set_return_type(ty);
                        func_name = "";
                }
        }
RC_E : RC {
                // print_table(tables);
                tables.END_SCOPE();
        }

Block : LC_B RC_E { $$ = new Node("Block"); }
        | LC_B BlockItems RC_E { $$ = $2; $$->rename("Block");}
BlockItems : BlockItem{ $$ = new Node("BlockItems"); $$->add(*$1); } 
        | BlockItems BlockItem{ $$ = $1; $$->add(*$2); 
        }

BlockItem : Decl {$$=$1; }| Stmt{$$=$1;}

Stmt : LVal ASSIGN Exp SEMI {$$ = new Node("AssignStmt"); $$->add(*$1); $$->add(*$3);
                // print_table(tables);
                cout <<"ASSIGN: "  << $1->get_type() << " " << $3->get_type() << endl;
                if($1->get_type()!=INT_TY || $3->get_type()!=INT_TY){
                        cout << "wrong type for AssignStmt" << endl;return 1;
                }
        }
        | Exp SEMI{ $$ = new Node("ExpStmt"); $$->add(*$1);  }
        | Block{$$=$1;}
        | IF LP Exp RP Stmt { $$ = new Node("IfStmt"); $$->add(*$3); $$->add(*$5); delete $3; delete $5; }
        | IF LP Exp RP Stmt ELSE Stmt { $$ = new Node("IfElseStmt"); $$->add(*$3); $$->add(*$5); $$->add(*$7); }
        | WHILE LP Exp RP Stmt { $$ = new Node("WhileStmt"); $$->add(*$3); $$->add(*$5);  }
        | BREAK SEMI {$$ = new Node("BreakStmt");}
        | CONTINUE SEMI {$$ = new Node("ContinueStmt");}
        | RETURN SEMI {$$ = new Node("ReturnStmt");
                if(tables.get_return_type()!=VOID_TY){
                        cout << "wrong return type" << endl;return 1;
                }
        }
        | RETURN Exp SEMI{$$= new Node("ReturenStmt"); $$->add(*$2);
                if(tables.get_return_type()!=INT_TY || $2->get_type()!=INT_TY){
                        cout << "wrong return type" << endl;return 1;
                }
        }

Exp : LOrExp {$$ = $1;}

LVal : ID {$$ = new Node("LVal" + $1->name()); $$->set_type(tables.get_var($1->name()));
        cout <<"HERE: " << $1->name() << " " << $$ -> get_type() <<endl; 
        $$->set_id($1->name());
        if(!tables.find_var($1->name())){
                cout << "undefined variable: " << $1->name() << endl;return 1;
        }
        }
        | ID Exps {$$ = $2;$$->rename("LVal" + $1->name()) ;
        Type ty;
        $$->set_id($1->name());
        if($2->children_size()==tables.get_var($1->name())-2) //magic number : 判断是否是数组最后一维
                ty = INT_TY;
        else if($2->children_size()==tables.get_var($1->name())-3)
                ty = ARRAY;
        else if($2->children_size()==tables.get_var($1->name())-4)
                ty = LIST_2;
        else if($2->children_size()==tables.get_var($1->name())-5)
                ty = LIST_3;
        else if($2->children_size()==tables.get_var($1->name())-6)
                ty = LIST_4;
        else if($2->children_size()==tables.get_var($1->name())-7)
                ty = LIST_5;
        else{
                cout << "undefined variable: " << $1->name() << endl;return 1;
        }

        cout << "ty: " << $1->name() << " " << ty << endl;
        $$->set_type(ty);
        if(!tables.find_var($1->name())){
                cout << "undefined variable: " << $1->name() << endl;return 1;
        }
        }
Exps : {$$ = new Node("Exps");}| Exps LB Exp RB{$$ = $1;$$->add(*$3); 
        if($3->get_type()!=INT_TY){
                cout << "wrong type for Exps" << endl;return 1;
        }
        }

PrimaryExp : LP Exp RP {$$ = $2;}| LVal {$$ = $1; }| Number{$$ = $1;

                $$->set_type(INT_TY);
        }

Number : INT_CONST{$$ = $1;}

UnaryExp : PrimaryExp {$$ = $1;} 
        | ID LP RP {$$ = $1;
                if(!tables.find_func($1->name())){
                        cout << "undefined function" << endl;return 1;
                }
                Type ty = tables.get_func($1->name())[0];
                $$->set_type(ty);
        } 
        | ID LP FuncRParams RP {$$ = $1;$$->add(*$3);
                if(!tables.find_func($1->name())){
                        cout << "undefined function" << endl;return 1;
                }
                vector<Type> params = tables.get_func($1->name());
                if(params.size()-1!=$3->children_size()){
                        cout << "wrong number of parameters" << endl;return 1;
                }


                cout << "Here" << endl;
                for(int i=0;i<$3->children_size();i++){
                        if(params[i+1]!=$3->get(i)->get_type()){
                                cout << "Param check " << i+1 << " " << params[i+1] << " " << $3->get(i)->get_type() << endl;
                                cout << "wrong type of parameters" << endl;return 1;
                        }else{
                                cout << "CHECK DIM_1: " << params[i+1] << " " << $3->get(i)->get_type() << endl;
                                if(params[i+1] >= 4){
                                        cout << "HERE" << endl;
                                        vector<int> array_length = tables.get_func_array($1->name())[i];
                                        string id = $3->get(i)->get_id();
                                        vector<int> array_length2 = tables.get_var_array(id);
                                        for(int j=0;j<array_length.size();j++){
                                                cout << "CHECK DIM: " << array_length[j] << " " << array_length2[j] << endl;
                                                if(array_length[j]!=array_length2[j]){
                                                        cout << "wrong type of parameters" << endl;return 1;
                                                }
                                        }

                                }
                        }
                }
                Type ty = params[0];
                $$->set_type(ty);
        }
        | UnaryOp UnaryExp{$$ = $2;$$->add(*$1);
                if($2->get_type()!=INT_TY){
                        cout << "wrong type for UnaryExp" << endl;return 1;
                }
        }

UnaryOp : ADD { $$ = new Node("ADD"); }| SUB { $$ = new Node("SUB") ;}| NOT{ $$ = new Node("NOT") ;}

FuncRParams : Exp { $$ = new Node("FuncRParams"); $$->add(*$1);$$->set_type($1->get_type()); delete $1;}
            | Exp COMMA FuncRParams {$$= $3; $$->add(*$1);$$->rename("FuncRParams");}


MulExp : UnaryExp {$$=$1;}
        | MulExp MUL UnaryExp {$$=new Node("MUL");$$->add(*$1);$$->add(*$3); 
        if($3->get_type()!=INT_TY)
               {
                cout << "wrong type for MulExp" << endl;return 1;}
                
        $$->set_type(INT_TY);
        }
        | MulExp DIV UnaryExp  {$$=new Node("DIV");$$->add(*$1);$$->add(*$3);
        if($3->get_type()!=INT_TY)
               { cout << "wrong type for MulExp" << endl;return 1;}
         $$->set_type(INT_TY);}
        | MulExp MOD UnaryExp  {$$=new Node("MOD");$$->add(*$1);$$->add(*$3);
        if($3->get_type()!=INT_TY)
               { cout << "wrong type for MulExp" << endl;return 1;}
         $$->set_type(INT_TY);}

AddExp : MulExp{$$=$1;} 
        | AddExp ADD MulExp {$$=new Node("ADD");$$->add(*$1);$$->add(*$3); $$->set_type(INT_TY);} 
        | AddExp SUB MulExp {$$=new Node("SUB");$$->add(*$1);$$->add(*$3); $$->set_type(INT_TY);}

RelExp : AddExp {$$=$1;}
        | RelExp LT AddExp {$$=new Node("LT");$$->add(*$1);$$->add(*$3); $$->set_type(INT_TY);} 
        | RelExp GT AddExp {$$=new Node("GT");$$->add(*$1);$$->add(*$3); $$->set_type(INT_TY);} 
        | RelExp LE AddExp {$$=new Node("LE");$$->add(*$1);$$->add(*$3); $$->set_type(INT_TY);} 
        | RelExp GE AddExp {$$=new Node("GE");$$->add(*$1);$$->add(*$3); $$->set_type(INT_TY);} 

EqExp : RelExp {$$=$1;}
        | EqExp EQ RelExp {$$=new Node("EQ");$$->add(*$1);$$->add(*$3); $$->set_type(INT_TY);} 
        | EqExp NE RelExp {$$=new Node("NE");$$->add(*$1);$$->add(*$3); $$->set_type(INT_TY);} 

LAndExp : EqExp {$$=$1;}
    | EqExp AND EqExp {$$=new Node("AND");$$->add(*$1);$$->add(*$3); $$->set_type(INT_TY); } 
LOrExp : LAndExp {$$=$1;}
    | LOrExp OR LAndExp {$$=new Node("OR");$$->add(*$1);$$->add(*$3);$$->set_type(INT_TY);} 

%%

void yyerror(const char *s) {
    printf("error: %s\n", s);
}