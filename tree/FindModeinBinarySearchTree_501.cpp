// Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

// If the tree has more than one mode, return them in any order.

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than or equal to the node's key.
// The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
// Both the left and right subtrees must also be binary search trees.

// Example 1:
// Input: root = [1,null,2,2]
// Output: [2]

// Example 2:
// Input: root = [0]
// Output: [0]
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -105 <= Node.val <= 105
 

// Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

#include "../common_headers.h"


// Sol 1: with hashmap
// Time: O(n) (n: #tree nodes)
// Space: O(n)
class Solution1{
    int maxCount = 0;

    void findModeHelper(TreeNode* root, unordered_map<int, int> &m){
        if(root == nullptr) return;
        
        if(m.find(root->val) == m.end()){
            m[root->val] = 1;
        }else{
            m[root->val] += 1;
        }

        maxCount = max(maxCount, m[root->val]);

        findModeHelper(root->left, m);
        findModeHelper(root->right, m);
    }

    public: 
    vector<int> findMode(TreeNode* root) {
        vector<int> rst;
        if(root == nullptr) return rst;
        unordered_map<int, int> umap;
        findModeHelper(root, umap);
        for(auto x: umap){
            if(x.second == maxCount){
                rst.push_back(x.first);
            }
        }
        return rst;
    }
};

int main(){
    //      1
    //     /  \
    //    2    3
    TreeNode x1(1);
    TreeNode x2(2);
    TreeNode x3(3);
    x1.left = &x2;
    x1.right = &x3;
    Solution1 s1;
    vector<int> rec1 = s1.findMode(&x1);
    cout << "test 1: " << endl;
    for(auto x: rec1){
        cout << x << endl;
    }


    //   1
    //    \
    //     2
    //   /
    // 2
    TreeNode x4(1);
    TreeNode x5(2);
    TreeNode x6(2);
    x4.right = &x5;
    x5.left = &x6;
    vector<int> rec2 = s1.findMode(&x4);
    cout << "test 2: " << endl;
    for(auto x: rec2){
        cout << x << endl;
    }
}