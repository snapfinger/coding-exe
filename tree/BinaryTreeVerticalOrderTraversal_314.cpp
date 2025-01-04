 #include "../common_headers.h"
 

// TC: O(N log N) (log N comes from the map operation, it is log h, 
// in the worst case (completely skewed tree, h = N)
 vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> rst;
        if(root == nullptr) return rst;
        queue<pair<int, TreeNode*>> q;
        map<int, vector<int>> m;
        q.push({0, root});
        while(!q.empty()){
            auto cur = q.front();
            int cur_idx = cur.first;
            TreeNode* cur_node = cur.second;
            m[cur_idx].push_back(cur_node->val);
            q.pop();
            if(cur_node->left != nullptr) q.push({cur_idx-1, cur_node->left});
            if(cur_node->right != nullptr) q.push({cur_idx+1, cur_node->right});
        }
        
        for(auto a: m){
            rst.push_back(a.second);
        }
        
        return rst;
    }