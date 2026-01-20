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
    ListNode* middleNode(ListNode* head) {
        //Brute Force Approach
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        int i=0;
        temp=head;
        while(i<cnt/2 && temp!=NULL){
            temp=temp->next;
            i++;
        }
        return temp;

        //Optimal Approach
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL ){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
