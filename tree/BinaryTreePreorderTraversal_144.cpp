// Given the root of a binary tree, return the preorder traversal of its nodes' values.

// Example 1:
// Input: root = [1,null,2,3]
// Output: [1,2,3]
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


// Sol 2: iterative
// Time: O(n)
// Space: O(h)
vector<int> preorderTraversal2(TreeNode* root) {
    vector<int> rst;
    if(root == nullptr) return rst;
    stack<TreeNode*> s;
    s.push(root);
    
    while(!s.empty()){
        TreeNode* cur_node = s.top();
        rst.push_back(cur_node->val);
        s.pop();
        if(cur_node -> right != nullptr) s.push(cur_node -> right);
        if(cur_node -> left != nullptr) s.push(cur_node -> left);
    }
    
    return rst;
}


// Sol 1: recursive
// Time: O(n), n: #tree nodes
// Space: O(h)
vector<int> preorderTraversal1(TreeNode* root) {
    vector<int> rst = {};
    preorderTraversalHelper(root, rst);
    return rst;
}

void preorderTraversalHelper(TreeNode* root, vector<int> &rst){
    if(root == nullptr) return;
    rst.push_back(root->val);
    preorderTraversalHelper(root->left, rst);
    preorderTraversalHelper(root->right, rst);
}
    