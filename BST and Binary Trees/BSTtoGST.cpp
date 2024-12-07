/**
 * Problem link: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
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
 * imagine as we have the inorder traversal and
 * performed a suffix sum
 * here we traversed the right subtree accumulate its sum then
 * update the value of the node
 * then go to the left subtree with the accumulated sum
 */

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int tmp = 0;
        inorderReversed(root , tmp);
        return root;
    }

    void inorderReversed(TreeNode* root, int& temp){
        if(!root) return;
        inorderReversed(root->right, temp);
        root->val+=temp;
        temp=root->val;
        inorderReversed(root->left,temp);
    }

    
};