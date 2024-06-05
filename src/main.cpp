#include "ast/ast.h"
extern FILE *yyin;
// #include <fmt/core.h>
#include <iostream>
using namespace std;
extern int yyparse();

Node root;
TABLE_LISTS tables;

int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " filename" << endl;
    return 1;
  }
  cout << "Parsing: " << argv[1] << endl;
  yyin = fopen(argv[1], "r");
  if (!yyin) {
    cout << "Cannot open file: " << argv[1] << endl;
    return 1;
  }
  cout << "CompUnit" << endl;
  tables.BEGIN_SCOPE();
  RUN_TIME_lib_Set(tables);
  int res = yyparse();


  tables.END_SCOPE();
  cout<<"begin output:"<<endl;
  root.print(0);
 
  return res;
}

