#include "../common_headers.h"

// TC: O(h)
// SC: O(1)
int closestValue(TreeNode* root, double target) {
    int rst = root->val;
    while(root != nullptr){
        if(abs(root->val - target) < abs(rst - target)){
            rst = root->val;
        }else if(abs(root->val - target) == abs(rst - target)){
            rst = min(root->val, rst);
        }
        
        root = (root->val > target) ? root->left: root->right;
    }
    
    return rst;
}