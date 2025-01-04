
// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
// Note: A leaf is a node with no children.

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: 2
// Example 2:

// Input: root = [2,null,3,null,4,null,5,null,6]
// Output: 5
 
// Constraints:
// The number of nodes in the tree is in the range [0, 105].
// -1000 <= Node.val <= 1000


#include "../common_headers.h"


// Level-order traversal
// Time: O(n)
// Space: O(n)
int minDepth(TreeNode* root) {
        int depth = 0;
        if(root == nullptr) return depth;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int cur_size = q.size();
            depth += 1;
            for(int i = 0; i < cur_size; i++){
                TreeNode* cur_node = q.front(); q.pop();
                if(cur_node -> left != nullptr) q.push(cur_node -> left);
                if(cur_node -> right != nullptr) q.push(cur_node -> right);
                else if(cur_node -> left == nullptr && cur_node -> right == nullptr){
                    return depth;
                }
            }
        }
        return depth;
    }