/**
 * Problem link: https://leetcode.com/problems/minimum-absolute-difference-in-bst
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
    vector<int> inorder;
    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        int ans = INT_MAX;
        for(int i = 1; i < inorder.size() ; i++) ans = min(ans , abs( inorder[i] - inorder[i-1] ));
        return ans; 
    }
    /**
     * get the inorder traversal then see the difference between each 
     * two adjacent values
     */
    void inOrder(TreeNode* cur){
        if(!cur) return;
        inOrder(cur->left);
        inorder.push_back(cur->val);
        inOrder(cur->right);
    }
};