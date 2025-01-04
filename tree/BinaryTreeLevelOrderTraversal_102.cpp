// 102. Binary Tree Level Order Traversal
// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]

// Example 2:
// Input: root = [1]
// Output: [[1]]

// Example 3:
// Input: root = []
// Output: []
 
// Constraints:
// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000

#include "../common_headers.h"


// Time complexity: O(n)
// Space complexity: O(n)
// n: number of nodes in the tree
vector<vector<int> > levelOrder(TreeNode* root) {
    vector<vector<int> > rst;
    if(root == nullptr) return rst;
    queue<TreeNode*> q1;
    q1.push(root); 

    while(!q1.empty()){
        int curSize = q1.size();
        vector<int> curRec;

        for(int i = 0; i < curSize; i++){
            TreeNode* curNode = q1.front();
            q1.pop(); 
            curRec.push_back(curNode->val );

            if(curNode->left != nullptr) q1.push(curNode->left);
            if(curNode->right != nullptr) q1.push(curNode->right);
        }
        
        rst.push_back(curRec);
        
    }

    return rst;
}


int main(){
    //     1
    //    /  \
    //   2    3
    TreeNode x1(1);
    TreeNode x2(2);
    TreeNode x3(3);
    x1.left = &x2;
    x1.right = &x3;

    vector<vector<int> > rst = levelOrder(&x1);
    vector<vector<int> >::iterator it;
    vector<int>::iterator i;

    for(it = rst.begin(); it != rst.end(); it++){
        cout << endl;
        for(i = (*it).begin(); i != (*it).end(); i++){
            cout << (*i) << " ";
        }
    }

    cout << endl;
}