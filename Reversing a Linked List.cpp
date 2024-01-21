//1st Approach
Node* reverseLinkedList(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;
    while(curr!=NULL)
    {
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;

    }
    return prev;
}

//2nd Approach
void solve(Node* &head, Node* curr, Node* prev)
{
    if(curr==NULL)
    {
        head=prev;
        return;
    }
    Node* forward=curr->next;
    solve(head, forward, curr);
    curr->next=prev;
}
Node* reverseLinkedList(Node *head)
{
    Node* curr=head;
    Node* prev=NULL;
    solve(head, curr, prev);
    return head;
} 

//3rd Approach
Node* reverse1(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* smallhead=reverse1(head->next);
    head->next->next=head;
    head->next=NULL;
    return smallhead;
}
Node* reverseLinkedList(Node *head)
{
    reverse1(head);
}
