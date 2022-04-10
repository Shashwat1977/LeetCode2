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
        if(head == NULL || head->next==NULL) return head;
        ListNode* prev=NULL;
        ListNode* curr = head;
        ListNode* temp = curr->next;
        while(curr != NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* reverse(ListNode* head,int k){
        if(head == NULL) return head;
        ListNode* curr = head;
        int count = 1;
        while(curr->next != NULL && count<k){
            count++;
            curr = curr->next;
        }
        ListNode* temp = curr->next;
        curr->next = NULL;
        ListNode* tempList = reverse(temp,k+1);
        if(count%2 == 0){
            ListNode* n = rev(head);
        head->next = tempList;
        return n;
        }else{
            curr->next = tempList;
            return head;
        }
        
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        return reverse(head,1);
    }
};