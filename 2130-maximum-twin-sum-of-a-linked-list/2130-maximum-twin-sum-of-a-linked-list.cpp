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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast->next!=NULL && fast!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* curr=slow->next;
        ListNode* after=NULL;
        ListNode* pre=NULL;
        while(curr!=NULL){
            after=curr->next;
            curr->next=pre;
            pre=curr;
            curr=after; 
        }
        slow->next=pre;
        ListNode* temp=head;
        slow=slow->next;
        int ans=INT_MIN;
        while(slow!=NULL){
            ans=max(temp->val+slow->val,ans);
            slow=slow->next;
            temp=temp->next;
        }
        return ans;
    }
};