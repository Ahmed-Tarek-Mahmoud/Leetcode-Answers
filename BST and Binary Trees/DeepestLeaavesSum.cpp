/**
 * Problem link: https://leetcode.com/problems/deepest-leaves-sum
 */

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
class Solution {
public:
    vector<int> val;
    int deepestLeavesSum(TreeNode* root) {
        int h = height(root);
        val.assign(h , 0);
        dfs(root , 0);
        return val[h-1];
    }

    /**
     * Calculate sum of each level and return the 
     * value of the last level 
     */

    void dfs(TreeNode * cur , int level){
        if(!cur) return;
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