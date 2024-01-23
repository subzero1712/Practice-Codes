Node* kReverse(Node* head, int k) {
    if(head==NULL){
        return NULL;
    }
    Node* prev=NULL;
    Node* forward=NULL;
    Node* curr=head;
    int counter=0;
    Node* temp=head;
    while(temp){
        temp=temp->next;
        counter++;
    }
    int count=0;
    if(k>counter){
        return head;
    }
    
    while(curr && count<k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }
    
    if(forward){
        head->next=kReverse(forward,k);
    }
    return prev;
}
