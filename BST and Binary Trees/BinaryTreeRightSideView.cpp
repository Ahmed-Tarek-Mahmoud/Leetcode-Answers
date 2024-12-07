/**
 * Problem link: https://leetcode.com/problems/binary-tree-right-side-view/
 */

/**
 * Definition for a binary tree node.
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /**
     * here we performed a BFS with some modification
     * order of insertion from right to left and made like a 
     * flag for each level wether i have seen a node in this level
     * before or not ;)
     */
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return vector<int>{};
        bool level[101] = {};
        queue<pair<TreeNode*,int>> bfs;
        bfs.push({root , 0});
        vector<int> ans;
        ans.push_back(root->val);
        while(!bfs.empty()){
            auto [cur , lvl] = bfs.front();
            bfs.pop();
            
            if(cur->right && !level[lvl + 1]){
                ans.push_back(cur->right->val);
                level[lvl + 1] = true;
            } 
            if(cur->right) bfs.push({cur->right , lvl+1});
            if(cur->left && !level[lvl + 1]){
                ans.push_back(cur->left->val);
                level[lvl + 1] = true;
            }
            if(cur->left) bfs.push({cur->left , lvl + 1});
        }
        return ans;
    }
};