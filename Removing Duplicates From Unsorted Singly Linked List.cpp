Node *removeDuplicates(Node *head) {
    if(head == NULL) {
        return head;
    }
    
    Node *curr = head;
    while(curr != NULL) {
        Node *temp = curr;
        while(temp->next != NULL) {
            if(curr->data == temp->next->data) {
                Node *nodetodelete = temp->next;
                temp->next = temp->next->next;
                delete nodetodelete;
            } else {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
}
