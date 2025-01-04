/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// TODO: iterative method


// recursive
// Time: O(N), n: #tree nodes
// Space: O(h), h: height of the tree
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> rst = {};
    postorderTraversalHelper(root, rst);
    return rst;
}

void postorderTraversalHelper(TreeNode* root, vector<int> &rst){
    if(root == nullptr) return;
    postorderTraversalHelper(root->left, rst);
    postorderTraversalHelper(root->right, rst);
    rst.push_back(root->val);
}
