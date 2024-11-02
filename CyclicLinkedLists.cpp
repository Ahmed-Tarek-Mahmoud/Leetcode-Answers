/**
 * Name: Ahmed Tarek
 * Date: 2 Nov 2024
 * Problem Link: https://leetcode.com/problems/linked-list-cycle/description/
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // in a linear linked list a fast pointer shouldn't meet the slow except 
        // once initially at the head
        ListNode * fast , *slow;
        fast = head;
        slow = head;
        
        // corner case handling single node and empty list 
        if(head == nullptr || head->next == nullptr) return false; 
        
        do{
            slow = slow->next;
            fast = fast->next;
            fast = (fast)?fast->next:nullptr; // if already null so keep it as it is
        }while(fast && slow && fast != slow);
        return fast == slow;
    }
};