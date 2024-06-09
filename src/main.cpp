#include "ast/ast.h"
#include "ir/ir.h"
extern FILE *yyin;
// #include <fmt/core.h>
#include <iostream>
using namespace std;
extern int yyparse();

Node root;
TABLE_LISTS tables;

int bb_num = 0;

std::unordered_map<std::string, BBs> Func_BB_map; // LOCAL, for func's basic blocks.
std::string cur_Func;
std::vector<Var_Type> cur_params;
Symbol_Table SYM_TBL;
std::set<string> GLOBALs;
int main(int argc, char **argv) {


if(argc == 3){
      FILE* file = freopen(argv[2], "w", stdout);

      if (file == nullptr) {
            std::cerr << "Failed to open output.txt" << std::endl;
            return 1;
        }

        // 输出重定向到 output.txt
        //std::cout << "This will be written to the file output.txt" << std::endl;
  }
  //cout << "Parsing: " << argv[1] << endl;
  yyin = fopen(argv[1], "r");
  if (!yyin) {
    cout << "Cannot open file: " << argv[1] << endl;
    return 1;
  }
  //cout << "CompUnit" << endl;
  tables.BEGIN_SCOPE();
  RUN_TIME_lib_Set(tables);
  int res = yyparse();


  tables.END_SCOPE();
  //cout << "IR: "<<endl;
  SYM_TBL.Stack.push(Field_Sym());//init symbol tbl
  //init_libs();
  traverseTree(root);
  
  //if(argc == 3)fclose(file);
  return res;
}

