/**
 * Name: Ahmed Tarek
 * Date: 2 Nov 2024
 * Problem Link: https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;
        ListNode* a = headA;
        ListNode* b = headB;
        // loop till finding intersection or one of the lists ends
        while( a != b){
            a = a == nullptr? headB : a->next;
            b = b == nullptr? headA : b->next;    
        }
        return a;
    }
};