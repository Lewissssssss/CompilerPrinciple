#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

enum Type{
    NONE,
    INT_TY,
    VOID_TY,
    ARRAY,
    LIST_2,
    LIST_3,
    LIST_4,
    LIST_5,
};

bool check_type(Type a, Type b);

void RUN_TIME_lib_Set(class TABLE_LISTS &tables);
void print_table(class TABLE_LISTS &tables);

class TABLE{
    public:
        map<string, Type> v_table;
        Type return_type;
        map<string, vector<int>> array_lenth;  // 用来查询数组的大小  
    public:
        void add_var(string name, Type type);
        Type get_var(string name);
        bool find_var(string name);
        void set_return_type(Type type);
        void set_var_array(string name, vector<int> lenth);
        vector<int> get_var_array(string name);
        Type get_return_type();
};

struct Func{
    string name;
    vector<Type> args;
    vector<vector<int>> array_lenth;
};

class TABLE_LISTS{
    public:
        vector<TABLE> tables;
        map<string, Func> f_table;

    public:
        void add_var(string name, Type type);
        void add_func(string name, vector<Type> &types);
        Type get_var(string name);
        vector<Type> get_func(string name);
        bool find_var(string name);
        Type get_var_in_scope(string name);
        void set_var_array(string name, vector<int> lenth);
        vector<int> get_var_array(string name);
        void set_func_array(string name, vector<vector<int>> lenth);
        vector<vector<int>> get_func_array(string name);
        
        bool find_func(string name);
        void set_return_type(Type type);
        Type get_return_type();

        void BEGIN_SCOPE();
        void END_SCOPE();
};

#undef ID
class Node{
    public:
        string type;  //expr or stmt
        Type t; // 数据类型
        string ID; // 变量名
        vector<int> array_size;
        vector<Node> children;

    public:
        Node(string type) : type(type),t(NONE) {}
        Node(){this->type = "Nope";this->t = NONE;};
        void add(Node &child);
        string name();
        Node *get(int i);
        int children_size();
        void rename(string name);
        void set_type(Type t);
        Type get_type();
        void print(int layer = 1);
        void set_id(string id);
        string get_id();
};