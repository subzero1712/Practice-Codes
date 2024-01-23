bool isCircular(node* head)
{
    if(head==NULL)
    {
        return true;
    }
    node* temp=head->next;
    while(temp != NULL && temp != head)
    {
        temp=temp->next;
    }
    if(temp==head)
    {
        return true;
    }
    if(temp==NULL)
    {
        return false;
    }
    return false;
    
}
