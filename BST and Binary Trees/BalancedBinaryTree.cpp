/**
 * Problem link: https://leetcode.com/problems/balanced-binary-tree/
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
    bool isBalanced(TreeNode* root) {
        return check(root);
    }
    
    // simply calculate left height and right height 
    // their absolute difference must be <= 1
    // then recursively check rigth and left subtrees

    bool check(TreeNode* cur){
        if(!cur) return true;
        int leftHeight = height(cur->left);
        int rightHeight = height(cur->right);
        return abs(leftHeight - rightHeight) <= 1
            && check(cur->left)
            && check(cur->right);
    }

    int height(TreeNode *p){
        if(!p) return 0; // null
        int x = height(p->left);
        int y = height(p->right);
        return max(x + 1 , y + 1);
    }
};