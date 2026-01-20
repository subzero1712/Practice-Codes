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
    ListNode* deleteMiddle(ListNode* head) {
        // if(head == NULL || head->next == NULL) return NULL;
        // int cnt = 0;
        // ListNode* temp = head;
        // while(temp != NULL){
        //     cnt++;
        //     temp = temp->next;
        // }
        // int mid = cnt / 2;   // middle index (0-based)
        // temp = head;
        // ListNode* prev = NULL;
        // for(int i = 0; i < mid; i++){
        //     prev = temp;
        //     temp = temp->next;
        // }
        // prev->next = temp->next;
        // delete temp;
        // return head;

        if(head==NULL || head->next==NULL) return NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
        delete slow;
        return head;
    }
};
