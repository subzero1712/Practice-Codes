Node* insertAtFirst(Node* head, int newValue) {
    Node* temp=new Node(newValue);
    temp->next=head;
    head=temp;
    return head;
}
