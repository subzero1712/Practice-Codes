Node *deleteLast(Node *head){
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }
    Node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    temp->next=nullptr;
    delete temp->next;
    return head;
}
