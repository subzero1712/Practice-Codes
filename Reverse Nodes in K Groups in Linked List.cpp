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
    ListNode* KthNode(ListNode* temp, int k){
        k--;
        while(temp!=NULL && k>0){
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseLL(ListNode* head){
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
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevLast=NULL;
        while(temp!=NULL){
            ListNode* Kth=KthNode(temp,k);
            if(Kth==NULL){
                if(prevLast) prevLast->next=temp;
                break;
            }
            ListNode* nextNode=Kth->next;
            Kth->next=NULL;
            reverseLL(temp);
            if(temp==head){
                head=Kth;
            }else{
                prevLast->next=Kth;
            }
            prevLast=temp;
            temp=nextNode;
        }
        return head;
    }
};
