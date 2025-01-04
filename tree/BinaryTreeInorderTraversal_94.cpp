// 94. Binary Tree Inorder Traversal

// Given the root of a binary tree, return the inorder traversal of its nodes' values. 

// Example 1:


// Input: root = [1,null,2,3]
// Output: [1,3,2]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [1]
// Output: [1]
 

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100
 

// Follow up: Recursive solution is trivial, could you do it iteratively?

#include "../common_headers.h"

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// recursive
// Time: O(n), n: #tree nodes
// Space: O(h), h: height of the tree
void InorderHelper(TreeNode* cur, vector<int> &rec){
    if(cur == nullptr) return;
    InorderHelper(cur->left, rec);
    rec.push_back(cur->val);
    InorderHelper(cur->right, rec);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> rst = {};
    InorderHelper(root, rst);
    return rst;
}

// TODO: iterative
// TODO: morris

int main(){
    TreeNode x1(1);
    TreeNode x2(2);
    TreeNode x3(3);
    x1.left = &x2;
    x1.right = &x3;
    vector<int> rec1 = inorderTraversal(&x1);
    for(auto r: rec1){
        cout << r << " ";
    }

    cout << endl;

}