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
    ListNode* tortoisehare(ListNode* head){
        if(head==NULL ||head->next==NULL){
            return head ;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow= slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* lefthead ,ListNode* righthead ){
        ListNode* h1 = lefthead;
        ListNode* h2 = righthead;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(h1!=NULL && h2!=NULL){
            if(h1->val < h2->val){
                temp->next=h1;
                temp = h1;
                h1=h1->next;
            }
            else{
                temp->next=h2;
                temp = h2;
                h2 = h2->next;
            }
        }
        if(h1!=NULL){
            temp->next=h1;
        }
        else{
            temp->next=h2;
        }
        return dummy->next;
    }


    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* middle = tortoisehare(head);
        ListNode* lefthead = head;
        ListNode* righthead = middle->next;
        middle->next= NULL;

        lefthead = sortList(lefthead);
        righthead = sortList(righthead);

        return merge(lefthead,righthead);

    }
};