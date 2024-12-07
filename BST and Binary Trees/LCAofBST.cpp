/**
 * Problem link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
 */

/**
 * Definition for a binary tree node.
 * */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;

        int cur = root->val;
        // p and q are in the left subtree 
        if(cur > p->val && cur > q->val)
            return lowestCommonAncestor(root->left, p, q);
        // p and q are in the right subtree
        if(cur < p->val && cur < q->val)
            return lowestCommonAncestor(root->right, p, q);
        // one right and one left so current node is the LCA
        return root;
    }
};