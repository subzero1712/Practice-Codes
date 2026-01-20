/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/
#include<bits/stdc++.h>
int lengthOfLoop(Node *head) {
    // unordered_map<Node*,int> mpp;
    // Node* temp=head;
    // int time=0;
    // while(temp!=NULL){
    //     if(mpp.find(temp)!=mpp.end()){
    //         return time-mpp[temp];
    //     }
    //     mpp[temp]=time++;
    //     temp=temp->next;
    // }
    // return 0;

    Node* slow=head;
    Node* fast=head;
    bool flag=false;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            flag=true;
            break;
        }
    }
    int cnt=0;
    while(true && flag){
        cnt++;
        fast=fast->next;
        if(fast==slow){
            return cnt;
            break;
        }
    }
    return 0;
}
