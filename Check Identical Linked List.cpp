int getLength(struct Node* head) {
    struct Node* temp = head;
    int len=0;
    while(temp!=NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}
bool areIdentical(struct Node *head1, struct Node *head2)
{
    int len = getLength(head1);
    int len2 = getLength(head2);
    if(len!=len2) {
        return 0;
    }
    else{
        while(len && len2) {
            if(head1->data != head2->data) {
                return 0;
            }
            head1 = head1->next;
            head2 = head2->next;
            len--;
            len2--;
        }
    }
    return 1;
}
