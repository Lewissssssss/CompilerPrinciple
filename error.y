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
                if(!tables.find_var($1->name())){
                        Type ty;
                        if($2->children_size()==0){
                                ty = INT_TY;
                        }else{
                                ty = ARRAY;}
                        
                        tables.add_var($1->name(),ty);
                }
                else
                        {
                        cout << "error: redefined variable: "<< $1->name() << endl ;return 1;
                        }
        }
        |ID ConstGroup {$$ = $2; $$->add(*$1); $$->rename("VerDef");
                if(!tables.find_var($1->name())){
                        Type ty;
                        if($2->children_size()==0){
                                ty = INT_TY;
                        }else{
                                ty = ARRAY;}
                        cout << "ADDR:" << $$ << " " << $1 << endl;
                        cout << "AddVar: " <<$1->name() << ty << endl;
                        tables.add_var($1->name(),ty);
                }
                else{
                        // for(int i=0;i<tables.tables.size();i++){
                        //         for(auto &[j,k]:tables.tables[i].v_table){
                        //                 cout <<"Table:" << j << endl;
                        //         }
                        // }

                        cout << "error: redefined variable: "<< $1->name() << endl ;return 1;}
        }
ConstGroup :{$$ = new Node("ConstGroup");}  
        |  LB INT_CONST RB ConstGroup {$$ = $1; $$->add(*$3);}

InitVal : Exp {$$ = $1;
        if($1->get_type()!=INT_TY){
                cout << "wrong type for Initval" << endl;return 1;
                
        }
        }

FuncDef : INT ID LP RP Block {printf("FuncDef\n"); $$ = new Node("FucDef "+$2->name() + "INT" );$$->add(*$5);
        if(tables.find_func($2->name())){
                cout << "error: redefined function" << endl;return 1;
                
        }
        else{
                vector<Type> params;
                params.push_back(INT_TY);
                tables.add_func($2->name(),params);
        } 
        } 
        | INT ID LP FuncFParams RP Block {$$ = new Node("FucDef "+$2->name() +"INT" );$$->add(*$4);$$->add(*$6);
        if(tables.find_func($2->name())){
                cout << "error: redefined function" << endl;return 1;
                
        }
        else{
                vector<Type> params;
                params.push_back(INT_TY);
                for(int i=0;i<$4->children_size();i++){
                        if($4->get(i)->name()=="ARRAY")
                                params.push_back(ARRAY);
                        else
                                params.push_back(INT_TY);
                        }
                tables.add_func($2->name(),params);
        }
        }
        | VOID ID LP RP Block {$$ = new Node("FucDef "+$2->name() + "VOID" );$$->add(*$5);
        if(tables.find_func($2->name())){
                cout << "error: redefined function" << endl;return 1;
                
        }
        else{
                vector<Type> params;
                params.push_back(VOID_TY);
                tables.add_func($2->name(),params);
        }
        }
        | VOID ID LP FuncFParams RP Block {$$ = new Node("FucDef "+$2->name() + "VOID" );$$->add(*$4);$$->add(*$6);
        if(tables.find_func($2->name())){
                cout << "error: redefined function" << endl;return 1;
                
        }
        else{
                vector<Type> params;
                params.push_back(VOID_TY);
                for(int i=0;i<$4->children_size();i++){
                        if($4->get(i)->name()=="ARRAY"){
                                Node* ptr = $4->get(i);
                                int Dim = ptr->children_size();
                                if(Dim==0)
                                        params.push_back(ARRAY);
                                else if(Dim==1)
                                        params.push_back(LIST_2);
                                else if(Dim==2)
                                        params.push_back(LIST_3);
                                else if(Dim==3)
                                        params.push_back(LIST_4);
                                else
                                        params.push_back(LIST_5);
                                
                        }
                        else
                                params.push_back(INT_TY);
                        }
                tables.add_func($2->name(),params);
        }
        }


FuncFParams : FuncFParam { $$ = new Node("FuncFParams"); $$->add(*$1); } 
        | FuncFParam  COMMA  FuncFParams { $$ = $3; $$->add(*$1); }


FuncFParam : INT ID { $$ = new Node("INT");}
        | INT ID LB RB ConstGroup{ $$ = new Node("ARRAY"); $$->add(*$5);}

LC_B : LC {tables.BEGIN_SCOPE(); }
RC_E : RC {tables.END_SCOPE();}

Block : LC_B RC_E { $$ = new Node("Block"); }
        | LC_B BlockItems RC_E { $$ = $2; $$->rename("Block");}
BlockItems : BlockItem{ $$ = new Node("BlockItems"); $$->add(*$1); } 
        | BlockItems BlockItem{ $$ = $1; $$->add(*$2); }

BlockItem : Decl {$$=$1; }| Stmt{$$=$1;}

Stmt : LVal ASSIGN Exp SEMI {$$ = new Node("AssignStmt"); $$->add(*$1); $$->add(*$3);
                if($3->get_type()!=INT_TY){
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
        | RETURN SEMI {$$ = new Node("ReturnStmt");}
        | RETURN Exp SEMI{$$= new Node("ReturenStmt"); $$->add(*$2);}

Exp : LOrExp {$$ = $1;}

LVal : ID {$$ = new Node("LVal" + $1->name());
        if(!tables.find_var($1->name())){
                cout << "undefined variable" << endl;return 1;
        }
        }
        | ID Exps {$$ = $2;$$->rename("LVal" + $1->name()) ;
        if(!tables.find_var($1->name())){
                // cout << "Here" << endl;
                print_table(tables);
                cout << "undefined variable" << endl;return 1;
        }
        }
Exps : {$$ = new Node("Exps");}| Exps LB Exp RB{$$ = $1;$$->add(*$3); }

PrimaryExp : LP Exp RP {$$ = $2;}| LVal {$$ = $1; $$->set_type(INT_TY); }| Number{$$ = $1;$$->set_type(INT_TY);}

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
                for(int i=0;i<$3->children_size();i++){
                        if(params[i+1]!=$3->get(i)->get_type()){
                                cout << "wrong type of parameters" << endl;return 1;
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


