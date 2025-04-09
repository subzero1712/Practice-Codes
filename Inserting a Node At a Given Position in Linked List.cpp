Node * insert(Node * head, int n, int pos, int val) {
    Node* temp=head;
    Node* no=new Node(val);
    if(pos==0){
        if(head==NULL){
            return no;
        }else{
            no->next=head;
            head=no;
            return head;
        }
    }
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
    }
    no->next=temp->next;
    temp->next=no;
    return head;
}
