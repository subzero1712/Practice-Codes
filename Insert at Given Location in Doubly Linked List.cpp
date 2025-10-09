//Insert Before The Given Element
#include <bits/stdc++.h> 
/************************************************************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int val) {
            this->data = val;
            next = NULL;
            prev = NULL;
        }
        ~Node() {
            if(next != NULL || prev != NULL){
                delete next;
            }
        }
};

************************************************************/

Node* insert(int pos, int val, Node *head) {
    Node* newNode = new Node(val);

    if (pos == 0) {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        return head;
    }

    Node* curr = head;
    int count = 0;

    while (curr != NULL && count < pos) {
        curr = curr->next;
        count++;
    }

    if (curr != NULL) {
        Node* before = curr->prev;
        before->next = newNode;
        newNode->prev = before;
        newNode->next = curr;
        curr->prev = newNode;
    } 

    else {
        Node* tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = newNode;
        newNode->prev = tail;
    }

    return head;
}

//Insert After Given Element
#include <bits/stdc++.h> 
/************************************************************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int val) {
            this->data = val;
            next = NULL;
            prev = NULL;
        }
        ~Node() {
            if(next != NULL || prev != NULL){
                delete next;
            }
        }
};

************************************************************/

Node* insert(int k, int val, Node *head) {
    Node* temp=head;
    Node* newNode=new Node(val);
    if(k==0){
        newNode->next=head;
        head->prev=newNode;
        newNode->prev=NULL;
        head=newNode;
    }
    else{
        for(int i=0;i<k-1;i++){
            temp=temp->next;
        }
        if(temp->next==NULL && temp->prev!=NULL){
            temp->next=newNode;
            newNode->prev=temp;
            newNode->next=NULL;
        }else{
            Node* nextNode=temp->next;
            nextNode->prev=newNode;
            newNode->next=nextNode;
            temp->next=newNode;
            newNode->prev=temp;
        }
    }
    
    return head;
}
