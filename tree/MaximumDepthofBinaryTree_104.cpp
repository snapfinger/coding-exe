// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: 3

// Example 2:
// Input: root = [1,null,2]
// Output: 2
 
// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// -100 <= Node.val <= 100


// Sol 3: iterative pre-order traversal
// TODO

// Sol 2: recursive post-order traversal
// Time: O(n)
// Space: O(h)
int maxDepth2(TreeNode* root) {
    if(root == nullptr) return 0;
    int l_max = maxDepth(root -> left);
    int r_max = maxDepth(root -> right);
    return max(l_max, r_max) + 1;
}


// Sol 1: level-order traversal with 1 queue
// Time: O(n)
// Space: O(n)
 int maxDepth1(TreeNode* root) {
        int depth = 0;
        if(root == nullptr) return depth;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int cur_size = q.size();
            depth += 1;
            for(int i = 0; i < cur_size; i++){
                TreeNode* cur_node = q.front(); q.pop();
                if(cur_node->left != nullptr) q.push(cur_node->left);
                if(cur_node->right != nullptr) q.push(cur_node->right);
            }
        }
        
        return depth;
    }