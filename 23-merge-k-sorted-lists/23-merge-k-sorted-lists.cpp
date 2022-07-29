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
struct cmp{//custom comparator for set
    bool operator()(ListNode* a, ListNode* b) const{
        return a->val>b->val;
    }  
};

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(int i = 0;i<lists.size();i++){
            if(lists[i]!= NULL) pq.push(lists[i]);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();
            if(temp->next){
                pq.push(temp->next);
            }
            tail->next = temp;
            tail = tail->next;
        }
        return dummy->next;
    }
};