/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        return swap(head);
    }
    ListNode* swap(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* temp = swap(second->next);
        second->next = first;
        first->next = temp;
        return second;
    }
};