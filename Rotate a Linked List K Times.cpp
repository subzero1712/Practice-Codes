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
    ListNode* KthElement(ListNode* head, int k){
        k--;
        while(head!=NULL && k>0){
            head=head->next;
            k--;
        }
        return head;
    }
    int len(ListNode* head){
        int cnt=0;
        while(head!=NULL){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n=len(head);
        if(n!=0) k=k%n;
        if(n<2 || k==0) return head;
        ListNode* temp=head;
        ListNode* prevHead=KthElement(temp,n-k);
        ListNode* headNext=prevHead->next;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;
        prevHead->next=NULL;
        head=headNext;
        return head;
    }
};
