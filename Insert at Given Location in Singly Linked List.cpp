#include <iostream>

using namespace std;
class node{
  public:
  int value;
  node *next;
  
  node(int data)
  {
      this->value=data;
      this->next=NULL;
  }
};


void insertattail(node* &tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = tail->next;
    
}
void print(node* &head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->value<<endl;
        temp=temp->next;
    }
}

void insertatposition(node* &head,int position, int d)
{
    if(position == 1)
    {
      insertathead();
      return;
    }
    node* temp=head;
    
    int count=1;
    while(count<position-1)
    {
        temp=temp->next;
        count++;
    }
    node *nodetoinsert = new node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
}

int main()
{
    node* node1 = new node(8);
    node *head=node1;
    node *tail=node1;
    int n,position=2;
    for(int i=0;i<5;i++){
        cin>>n;
    cout<<"the list is"<<endl;
    insertattail(tail, n);
    print(head);
    }
    insertatposition(head,2,5);
    print(head);
}
