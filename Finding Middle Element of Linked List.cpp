//1st Approach
int getlength(Node* head)
{
    int len=0;
    while(head!=NULL)
    {
        len++;
        head=head->next;
    }
    return len;
}

Node *findMiddle(Node *head) {
    int len=getlength(head);
    int ans=(len/2);

    Node* temp=head;
    int cnt=0;
    while(cnt<ans)
    {
        temp=temp->next;
        cnt++;
    }
    return temp;    
}

//2nd Approach
Node* getmiddle(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    if(head->next->next==NULL)
    {
        return head->next;
    }
    Node* fast=head->next;
    Node* slow=head;
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next; 
    }
    return slow;
}
Node *findMiddle(Node *head) {
    getmiddle(head); 
}
