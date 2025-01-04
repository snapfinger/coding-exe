#include "../common_headers.h"

class Solution{

int count1 = 0;


void preOrder1(TreeNode* root, int max){
    if(root==nullptr) return;
    if(root->val >= max){
        count1++;
        max = root->val;
    }

    preOrder1(root->left, max);
    preOrder1(root->right, max);

    return;
}

public:
    // sol 1: recursive DFS
    // time: O(n)
    // space: O(h)
    int goodNodes1(TreeNode* root) {
        preOrder1(root, INT_MIN);
        return count1;       
    }

    // sol 2: iterative DFS
    // time: O(n)
    // space: O(n)
    int goodNodes2(TreeNode* root){
        int count = 0;
        stack<pair<TreeNode*, int> > s;
        s.push(pair(root, INT_MIN));

        while(!s.empty()){
            pair<TreeNode*, int> cur_pair = s.top();
            TreeNode* cur_node = cur_pair.first;
            int cur_max = cur_pair.second;
            s.pop();

            if(cur_node->val >= cur_max){
                count++;
            }

            if(cur_node->right != nullptr){
                s.push(pair(cur_node->right, max(cur_max, cur_node->val)));
            }

            if(cur_node->left != nullptr){
                s.push(pair(cur_node->left, max(cur_max, cur_node->val)));
            }
        }

        return count;
    }

    // sol 3: iterative BFS
    // time: O(n)
    // space: O(n)
    int goodNodes3(TreeNode* root){
        int count = 0;
        queue<pair<TreeNode*, int> > q;
        q.push(pair(root, INT_MIN));

        while(!q.empty()){
            pair<TreeNode*, int> cur_pair = q.front();
            TreeNode* cur_node = cur_pair.first;
            int cur_max = cur_pair.second;
            q.pop();

            if(cur_node->val >= cur_max){
                count++;
            }

            if(cur_node->left != nullptr){
                q.push(pair(cur_node->left, max(cur_max, cur_node->val)));
            }

            if(cur_node->right != nullptr){
                q.push(pair(cur_node->right, max(cur_max, cur_node->val)));
            }
        }

        return count;
    }
};


int main(){
    Solution s;

    // Example 2
    TreeNode t1 = TreeNode(3);
    TreeNode t2 = TreeNode(3);
    TreeNode t3 = TreeNode(4);
    TreeNode t4 = TreeNode(2);

    TreeNode* t1p = &t1;
    TreeNode* t2p = &t2;
    TreeNode* t3p = &t3;
    TreeNode* t4p = &t4;

    t1p->left = t2p;
    t2p->left = t3p;
    t2p->right = t4p;

    std::cout << s.goodNodes1(t1p) << std::endl;
    std::cout << s.goodNodes2(t1p) << std::endl;
}   