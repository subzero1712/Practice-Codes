Node* kReverse(Node* head, int k) {
    if(head == nullptr)
    {
        return nullptr;
    }
    Node* next;
    Node* curr = head;
    Node* prev = nullptr;

    int count=0;
    while(curr != nullptr && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next != nullptr){   
        head->next = kReverse(next,k);     
    }
    return prev;
}
