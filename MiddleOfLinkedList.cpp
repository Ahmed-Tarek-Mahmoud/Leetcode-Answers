/**
 * Name: Ahmed Tarek
 * Date: 2 Nov 2024
 * Problem Link: https://leetcode.com/problems/middle-of-the-linked-list/description/
 */

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // here we used a technique called slow and fast pointers you can search 
        // for an animation to know why is that always true
        ListNode * fast , *slow;
        fast = head;
        slow = head;
        while(fast && fast->next!= nullptr){
            slow= slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
};