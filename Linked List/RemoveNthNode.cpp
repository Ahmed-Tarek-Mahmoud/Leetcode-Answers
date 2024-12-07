/**
 * Name: Ahmed Tarek
 * Date: 30 Oct 2024
 * Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        // simple solution is to scan the list and get its length first
        // then do another scan to delete the nth node
        int len =0;
        ListNode * tmp = head;
        while(tmp != nullptr){
            len++;
            tmp = tmp->next;
        }
        tmp = head;
        int cur = 0 , toDelete = len - n;
        if(n == len){
            return head->next;
        }
        ListNode * prev = tmp;
        while(cur < toDelete){
            prev = tmp;
            tmp = tmp->next;
            cur++;
        }
        prev->next = tmp->next;
        tmp->next = nullptr;
        return head;
    }
};