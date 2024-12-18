/**
 * Problem link: https://leetcode.com/problems/validate-binary-search-tree
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
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        for(int i = 1; i < inorder.size() ; i++){
            if(inorder[i] <= inorder[i-1]) return false;
        }
        return true;
    }
    // Use the fact of inorder traversal of a valid
    // BST is a sorted array
    void inOrder(TreeNode* cur){
        if(!cur) return;
        inOrder(cur->left);
        inorder.push_back(cur->val);
        inOrder(cur->right);
    }
    
};