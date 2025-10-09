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

Node* deleteHead(Node* head) {
    if (head == NULL)
        return NULL;

    Node* temp = head;         
    head = head->next;        

    if (head != NULL)
        head->prev = NULL;

    temp->next = NULL;
    delete temp;

    return head;
}
