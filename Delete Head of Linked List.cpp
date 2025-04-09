Node * deleteHead(Node *head) {
    if(head==NULL) return NULL;
    Node* temp=head;
    temp=head->next;
    delete head;
    head=temp;
    return head;
}
