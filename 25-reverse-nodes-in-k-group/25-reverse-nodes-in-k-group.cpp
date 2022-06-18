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
    ListNode* rev(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head->next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverse(ListNode* head,int k){
        if(head == NULL) return head;
        ListNode* curr = head;
        int count = 1;
        while(curr -> next != NULL && count<k){
            count++;
            curr = curr->next;
        }
        if(count<k) return head;
        ListNode* temp = curr->next;
        curr->next = NULL;
        ListNode* templist = reverse(temp,k);
        ListNode* n = rev(head);
        head->next = templist;
        return n;
        }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverse(head,k);
    }
};