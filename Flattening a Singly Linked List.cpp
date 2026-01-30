/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
#include<bits/stdc++.h>
Node* merge(Node* temp1, Node* temp2){
    Node* dummy=new Node(-1);
    Node* dumNxt=dummy;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<temp2->data){
            dumNxt->child=temp1;
            dumNxt=dumNxt->child;
            temp1=temp1->child;
        }
        else if(temp1->data>temp2->data){
            dumNxt->child=temp2;
            dumNxt=dumNxt->child;
            temp2=temp2->child;
        }
    }
    while(temp1!=NULL){
        dumNxt->child=temp1;
        dumNxt=dumNxt->child;
        temp1=temp1->child;
    }
    while(temp2!=NULL){
        dumNxt->child=temp2;
        dumNxt=dumNxt->child;
        temp2=temp2->child;
    }
    dumNxt->next=NULL;
    return dummy->child;
}
Node* func(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* mergeHead=func(head->next);
    return merge(head,mergeHead);
}
Node* flattenLinkedList(Node* head) 
{
	// Node* temp1=head;
    // vector<int> ans;
    // while(temp1!=NULL){
    //     ans.push_back(temp1->data);
    //     Node* temp2=temp1;
    //     while(temp2!=NULL){
    //         if(temp1!=temp2) ans.push_back(temp2->data);
    //         temp2=temp2->child;
    //     }
    //     temp1=temp1->next;
    // }
    // sort(ans.begin(), ans.end());
    // Node* dummy=new Node(-1);
    // Node* temp=dummy;
    // for(int i=0;i<ans.size();i++){
    //     Node* newNode=new Node(ans[i]);
    //     temp->child=newNode;
    //     temp=temp->child;
    // }
    // return dummy->child;
    return func(head);
}
