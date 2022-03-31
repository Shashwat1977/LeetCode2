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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL || head->next==NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i = 1;i<k;i++){
            fast = fast->next;
        }
        ListNode* one = fast;
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        int temp = slow->val;
        slow->val = one->val;
        one->val = temp;
        return head;
    }
};