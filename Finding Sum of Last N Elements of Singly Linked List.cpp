int sumOfLastN_Nodes(struct Node* head, int n)
{
      Node* temp=head;
      int count=0;
      while(temp!=NULL)
      {
        count++;
        temp=temp->next;
      }
      
      temp=head;
      int j=count-n+1;
      int cnt=0;
      int sum=0;
      while(temp!=NULL)
      {
          cnt++;
          if(cnt==j)
          {
              sum=sum+temp->data;
              j++;
          }
          temp=temp->next;
      }
      return sum;
}
