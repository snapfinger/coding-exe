#include "../common_headers.h"


// Each employee have have multiple other employees report to them
// Count the number of employees plus themselves, call it "employee score"
// e.g. 
//        a
//      /   \
//     b     c
//    /
//   d
// then a has employee score of 4

// TODO
// What if we have the employee score for everyone, 
// after some movement of some employees, update the scores for every one
// Idea: the score of the children of an employee will not be affected by the employee's movement
// only the parents will be affected

struct employee{
    string name;
    vector<employee*> children;
    employee(): name(""), children(vector<employee*>()){};
    employee(string n): name(n), children(vector<employee*>()){};
};

void dfsHelper(employee* root, int& rst){
    cout << root->name << " ";
    if(root->name == "") return;
    
    rst += 1;
    cout << "cnt: " << rst << endl;
    cout << " " << root->children.size() << endl;
    for(auto c: root->children){
        dfsHelper(c, rst);
    }

}

int get_report_num(employee* root){
    int rst = 0;
    dfsHelper(root, rst);
    return rst;
}

int main(){
    employee* a = new employee("alice");
    employee* b = new employee("bob");
    employee* c = new employee("kelly");
    employee* d = new employee("david");
    employee* e = new employee("ealisa");
    a->children.push_back(b);
    a->children.push_back(c);
    a->children.push_back(d);
    b->children.push_back(e);
    cout << get_report_num(a) << endl;

}