/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getDifference(node* head1, node* head2) {
    //     int len1 = 0, len2 = 0;
    //     while (head1 != NULL || head2 != NULL) {
    //         if (head1 != NULL) {
    //             ++len1;
    //             head1 = head1->next;
    //         }
    //         if (head2 != NULL) {
    //             ++len2;
    //             head2 = head2->next;
    //         }
    //     }
    //     return len1 - len2;  // If negative, length of list2 > length of list1, else vice-versa
    // }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //Better Approach
        // map<ListNode*, int> mpp;
        // ListNode* temp1=headA;
        // ListNode* temp2=headB;
        // while(temp1!=NULL){
        //     mpp[temp1]++;
        //     temp1=temp1->next;
        // }
        // while(temp2!=NULL){
        //     mpp[temp2]++;
        //     if(mpp[temp2]==2) return temp2;
        //     temp2=temp2->next;
        // }
        // return NULL;

        //Optimal solution 2
        //  int diff = getDifference(head1, head2);
        //   if (diff < 0) 
        //   while (diff++ != 0) head2 = head2->next;
        //   else 
        //         while (diff-- != 0) head1 = head1->next;
        //     while (head1 != NULL) {
        //         if (head1 == head2) return head1;  
        //         head2 = head2->next;
        //         head1 = head1->next;
        //     }
        //     return head1;  
        // }

        //Optimal Solution 1
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp1==temp2) return temp1;
            if(temp1==NULL) temp1=headB;
            if(temp2==NULL) temp2=headA;
        }
        return temp1;
    }
};
