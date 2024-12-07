/**
 * Problem link: https://leetcode.com/problems/average-of-levels-in-binary-tree
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

/**
 * Idea is to run a dfs and accumulate the values of each level
 * in a vector and the count of nodes in each level in another vector
 * then you can easily calculate the average
 */

class Solution {
public:
    vector<double> val;
    vector<int> cnt;

    vector<double> averageOfLevels(TreeNode* root) {
        int h = height(root);
        vector<double> ans(h , 0);
        val.assign(h , 0);
        cnt.assign(h , 0);
        dfs(root , 0);
        for(int i = 0; i < h ; i++){
            ans[i] = (double)(val[i] / cnt[i]);
        }
        return ans;
    }

    void dfs(TreeNode * cur , int level){
        if(!cur) return;
        cnt[level]++;
        val[level] += cur->val;
        dfs(cur->left , level + 1);
        dfs(cur->right , level + 1);
    }

    int height(TreeNode *p){
        if(!p) return 0; // null
        int x = height(p->left);
        int y = height(p->right);
        return max(x + 1 , y + 1);
    }
};