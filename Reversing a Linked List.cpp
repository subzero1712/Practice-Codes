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
    ListNode* reverseList(ListNode* head) {
        //Brute Force
        stack<int> st;
        ListNode* temp=head;
        while(temp!=NULL){
            st.push(temp->val);
        }
        temp=head;
        while(temp!=NULL){
            temp->val=st.top();
            st.pop();
        }
        return head;

        //Iterative
        ListNode* front=head;
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=NULL){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;

        //Recursive
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* newHead=reverseList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newHead;
    }
};
