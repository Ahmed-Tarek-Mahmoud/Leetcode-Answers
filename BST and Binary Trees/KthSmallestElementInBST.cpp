/**
 * Problem link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
 * the in order traversal of a BST is a sorted array
 * so we got that array and return the Kth element in it
 */

class Solution {
public:
    vector<int> inorder;
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root);
        return inorder[k-1];
    }
    void inOrder(TreeNode* cur){
        if(!cur) return;
        inOrder(cur->left);
        inorder.push_back(cur->val);
        inOrder(cur->right);
    }
};