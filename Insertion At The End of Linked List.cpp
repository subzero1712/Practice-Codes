class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        Node *n=head;
        Node* temp=new Node(x);
        if(head==NULL) return temp;
        while(n->next!=NULL){
            n=n->next;
        }
        n->next=temp;
        temp->next=NULL;
        return head;
    }
};
