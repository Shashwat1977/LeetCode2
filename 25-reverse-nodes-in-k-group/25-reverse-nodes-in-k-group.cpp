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
        ListNode* temp = head->next;
        while(curr != NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* reverse(ListNode* head,int k){
        if(head == NULL) return NULL;
        ListNode* curr = head;
        int count = 1;
        while(curr->next!= NULL && count<k){
            curr = curr->next;
            count++;
        }
        if(count<k) return head;
        
        ListNode* temp = curr->next;
        curr->next = NULL;
        ListNode* tempList = reverse(temp,k);
        ListNode* n = rev(head);
        head->next = tempList;
        return n;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverse(head,k);
    }
};