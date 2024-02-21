Node* mergeTwoLists(Node* a, Node* b) {
    
    Node *temp = new Node(0);
    Node *res = temp; 
    
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->child = a; 
            temp = temp->child; 
            a = a->child; 
        }
        else {
            temp->child = b;
            temp = temp->child; 
            b = b->child; 
        }
    }
    
    if(a) temp->child = a; 
    else temp->child = b; 
    
    return res -> child; 
    
}

Node* flattenLinkedList(Node* head) 
{
	if (head == NULL || head->next == NULL) 
            return head; 
  
        // recur for list on right 
        head->next = flattenLinkedList(head->next); 
  
        // now merge 
        Node* ans = mergeTwoLists(head, head->next); 
  
        // return the root 
        // it will be in turn merged with its left 
        return ans; 
}
