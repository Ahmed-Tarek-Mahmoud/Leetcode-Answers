/**
 * Problem link:https://leetcode.com/problems/range-sum-of-bst/
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
 * get the sorted array using inorder traversal then
 * lower bound on the starting index and keep summing up 
 * till being higher than [high]
 * lower bound(val) -> first index greater than or equal val
 */

class Solution {
public:
    vector<int>inorder;
    int rangeSumBST(TreeNode* root, int low, int high) {
        inOrder(root);
        int start = lower_bound(inorder.begin() ,inorder.end() , low ) - inorder.begin();
        int sum = 0 , n = inorder.size();
        while(start < n && inorder[start] <= high){
            sum += inorder[start];
            start++;
        }
        return sum;
    }

    void inOrder(TreeNode* cur){
        if(!cur) return;
        inOrder(cur->left);
        inorder.push_back(cur->val);
        inOrder(cur->right);
    }
};