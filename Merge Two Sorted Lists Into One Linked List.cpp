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
    ListNode* mergeTwoLists(ListNode* temp1, ListNode* temp2) {
        ListNode* head=new ListNode(-1);
        ListNode* temp=head;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<=temp2->val){
                temp->next=new ListNode(temp1->val);
                temp1=temp1->next;
            }else{
                temp->next=new ListNode(temp2->val);
                temp2=temp2->next;
            }
            temp=temp->next;
        }
        while(temp1!=NULL){
            temp->next=new ListNode(temp1->val);
            temp1=temp1->next;
            temp=temp->next;
        }
        while(temp2!=NULL){
            temp->next=new ListNode(temp2->val);
            temp2=temp2->next;
            temp=temp->next;
        }
        return head->next;
    }
};
