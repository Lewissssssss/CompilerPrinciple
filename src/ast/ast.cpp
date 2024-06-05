#include "ast/ast.h"

void Node::add(Node &child){
    this->children.push_back(child);
}

string Node::name(){
    return this->type;
}

void Node::rename(string name){
    this->type = name;
}

Type Node::get_type(){
    return this->t;
}

void Node::print(int layer){
    cout << string(layer*4, ' ') << this->type << endl;
    // if(get_type() == ARRAY){
    //     cout<<"ALALALALALALALALALAL"<<endl;
    //     for (int size : this->array_size){
    //         cout<<size<<endl;
    //     }
    // }
    for (Node child : this->children){
        child.print(layer + 1);
    }
}

int Node::children_size(){
    return this->children.size();
}

void Node::set_type(Type t){
    this->t = t;
}

void Node::set_id(string id){
    this->ID = id;
}

string Node::get_id(){
    return this->ID;
}

Node *Node::get(int i){
    return &this->children[i];
}



void TABLE::add_var(string name, Type type){
    this->v_table[name] = type;
}



Type TABLE::get_var(string name){
    return this->v_table[name];
}


bool TABLE::find_var(string name){
    return this->v_table.find(name) != this->v_table.end();
}

void TABLE::set_return_type(Type type){
    this->return_type = type;
}

Type TABLE::get_return_type(){
    return this->return_type;
}

void TABLE::set_var_array(string name, vector<int> lenth){
    this->array_lenth[name] = lenth;
}

vector<int> TABLE::get_var_array(string name){
    return this->array_lenth[name];
}


void TABLE_LISTS::BEGIN_SCOPE(){
    this->tables.push_back(TABLE());
}

void TABLE_LISTS::END_SCOPE(){
    this->tables.pop_back();
}

Type TABLE_LISTS::get_var(string name){
    for (int i = this->tables.size() - 1; i >= 0; i--){
        if(tables[i].find_var(name)){
            return tables[i].get_var(name);
        }
    }
    return NONE;
}

bool TABLE_LISTS::find_var(string name){
    for (int i = this->tables.size() - 1; i >= 0; i--){
        if(tables[i].find_var(name)){
            return true;
        }
    }
    return false;
}


bool TABLE_LISTS::find_func(string name){
    return this->f_table.find(name) != this->f_table.end();
}



vector<Type> TABLE_LISTS::get_func(string name){
    return this->f_table[name].args;
}


void TABLE_LISTS::add_var(string name, Type type){
    this->tables.back().add_var(name, type);
}


void TABLE_LISTS::add_func(string name, vector<Type> &types){
    vector<vector<int>> temp_arr;
    Func temp = {name, types, temp_arr};
    this->f_table[name] = temp ;
}

Type TABLE_LISTS::get_var_in_scope(string name){
    return this->tables.back().get_var(name);
}

void TABLE_LISTS::set_return_type(Type type){
    this->tables.back().set_return_type(type);
}

Type TABLE_LISTS::get_return_type(){
    for(int i = this->tables.size() - 1; i >= 0; i--){
        if (this->tables[i].get_return_type() != NONE){
            return this->tables[i].get_return_type();
        }
    }
    return NONE;
}

void TABLE_LISTS::set_var_array(string name, vector<int> lenth){
    this->tables.back().set_var_array(name, lenth);
}

vector<int> TABLE_LISTS::get_var_array(string name){
    for(int i = this->tables.size() - 1; i >= 0; i--){
        if (this->tables[i].get_var_array(name).size() != 0){
            return this->tables[i].get_var_array(name);
        }
    }
    return vector<int>();
}

void TABLE_LISTS::set_func_array(string name, vector<vector<int>> lenth){
    f_table[name].array_lenth = lenth;
}

vector<vector<int>> TABLE_LISTS::get_func_array(string name){
    return f_table[name].array_lenth;
}

void RUN_TIME_lib_Set(TABLE_LISTS &tables){
    vector<Type> getint_args = {INT_TY};
    tables.add_func("getint",getint_args);
    vector<Type> getchar_args = {INT_TY};
    tables.add_func("getch",getchar_args);
    vector<Type> getarray_args = {INT_TY,ARRAY};
    tables.add_func("getarray",getarray_args);
    vector<Type> putint_args = {VOID_TY,INT_TY};
    tables.add_func("putint",putint_args);
    vector<Type> putchar_args = {VOID_TY,INT_TY};
    tables.add_func("putch",putchar_args);
    vector<Type> putarray_args = {VOID_TY,INT_TY,ARRAY};
    tables.add_func("putarray",putarray_args);
    vector<Type> starttime_args = {VOID_TY};
    tables.add_func("starttime",starttime_args);
    vector<Type> stoptime_args = {VOID_TY};
    tables.add_func("stoptime",stoptime_args);
}





