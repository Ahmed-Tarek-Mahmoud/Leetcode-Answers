/**
 * Problem link: https://leetcode.com/problems/maximum-depth-of-binary-tree
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
    int maxDepth(TreeNode* root) {
        return height(root);
    }
    int height(TreeNode *p){
        if(!p) return 0; // null
        int x = height(p->left);
        int y = height(p->right);
        return max(x + 1 , y + 1);
    }
};