/**
 * Problem link: https://leetcode.com/problems/symmetric-tree/
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
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
    /* check if the two nodes are mirror to each other by
    // checking the left and right
    //          4
    //         / \
    //        2   2
    //       / \ / \ 
    //      1  5 5  1
    // Return True
    */
    bool check(TreeNode* node1 , TreeNode* node2){
        if( !node1 && ! node2 ) return true; // both leaf nodes
        if( !node1 || ! node2 ) return false;// one of them leaf and other not
        return node1->val == node2->val 
            && check(node1 -> left , node2-> right)
            && check(node1->right , node2->left); 
    }
};