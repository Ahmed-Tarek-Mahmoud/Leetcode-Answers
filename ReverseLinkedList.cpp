/**
 * Name: Ahmed Tarek
 * Date: 2 Nov 2024
 * Problem Link: https://leetcode.com/problems/reverse-linked-list/description/
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    // recursive solution 
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* h2 = reverseList(head->next); // my new head
        head->next->next = head;
        head->next=prev;
        return h2;
    }

    // iterative solution using 3 sliding pointers
    ListNode* reverseList(ListNode* head) {
        ListNode *p = head, *q = nullptr, *r = nullptr;
        while(p != nullptr){
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        // p will be out and q will be standing on the last node
        return q;
    }
};