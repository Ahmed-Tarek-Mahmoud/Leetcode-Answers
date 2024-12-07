/**
 * Name: Ahmed Tarek
 * Date: 30 Oct 2024
 * Problem Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == nullptr) return;

        node->val = node->next->val; // copy the value of next node as if i am skipping it
        ListNode* todelete = node->next;
        node->next = node->next->next;
        delete todelete;

    }
};