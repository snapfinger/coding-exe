#include <utility>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <functional>
#include <numeric>
#include <bitset>
#include <list>
#include <format>
#include <iomanip>
#include <unordered_set>
#include <set>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void print2D(vector<vector<int> >& mat){
     for(auto row: mat){
          for(auto col: row){
               cout << col << " ";
          }
          cout << endl;
     }
}


void print2D(vector<vector<float> >& mat){
     for(auto row: mat){
          for(auto col: row){
               // cout << col << " ";
               printf("%.3f ", col);
          }
          cout << endl;
     }
}

void print1D(vector<int>& vec){
     for(auto val: vec){
          cout << val << " ";
     }
     cout << endl;
}


void printDict(map<int, vector<pair<int, int> > > dict){
    for(auto &m: dict){
        cout << m.first << ": ";

        for(auto &p: m.second){
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }
}
