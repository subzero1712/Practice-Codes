Node *deleteNode(Node *head, int pos)
{
	if(head == NULL) return NULL;

    if(pos == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

	Node* temp = head;
	for(int i = 0; i < pos - 1 && temp->next != NULL; i++) {
		temp = temp->next;
	}
    if(temp->next != NULL) {
        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }

	return head;
}
