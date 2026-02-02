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
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode* merge(ListNode* temp1, ListNode* temp2){
        ListNode* dummy=new ListNode(-1);
        ListNode* dum=dummy;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<=temp2->val){
                dum->next=temp1;
                dum=dum->next;
                temp1=temp1->next;
            }
            else if(temp2->val<temp1->val){
                dum->next=temp2;
                dum=dum->next;
                temp2=temp2->next;
            }
        }
        while(temp1!=NULL){
            dum->next=temp1;
            dum=dum->next;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            dum->next=temp2;
            dum=dum->next;
            temp2=temp2->next;
        }
        dum->next=NULL;
        return dummy->next;
    }
    ListNode* ms(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* middle=findMiddle(head);
        ListNode* lefthead=head;
        ListNode* righthead=middle->next;
        middle->next=NULL;
        ListNode* left=ms(lefthead);
        ListNode* right=ms(righthead);
        return merge(left,right);
    }
    ListNode* sortList(ListNode* head) {
        // vector<int> ans;
        // ListNode* temp=head;
        // while(temp!=NULL){
        //     ans.push_back(temp->val);
        //     temp=temp->next;
        // }
        // sort(ans.begin(), ans.end());
        // ListNode* dummy=new ListNode(-1);
        // ListNode* dum=dummy;
        // for(int i=0;i<ans.size();i++){
        //     dum->next=new ListNode(ans[i]);
        //     dum=dum->next;
        // }
        // dum->next=NULL;
        // return dummy->next;

        return ms(head);
    }
};
