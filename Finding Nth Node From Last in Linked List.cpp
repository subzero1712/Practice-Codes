Node* nthNodeFromEnd(Node* head, int n)
{
    if(head==NULL)
	{
		return head;
	}
	Node* temp=head;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	temp=head;
	for(int i=0;i<(count-n);i++)
	{
		temp=temp->next;
	}
	return temp;
}
