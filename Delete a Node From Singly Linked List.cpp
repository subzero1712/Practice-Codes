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

  ~node()
  {
      int value = this->value;
      if(this->next!=NULL)
      {
          delete next;
          this->next=NULL;
      }
      cout<<"memory is free for the value "<<value<<endl;
  }
};

void print(node* &head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->value<<endl;
        temp=temp->next;
    }
}

void insertathead(node* &head, int d)
{
    node* temp = new node(d);
    temp->next=head;
    head=temp;
    
}

void insertattail(node* &tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = tail->next;
    
}

void insertatposition(node* tail,node* &head,int position, int d)
{
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

void deletenode(node* &head, int position)
{
    if(position==1)
    {
        node* temp = head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        int cnt=0;
        node* curr=head;
        node* prev=NULL;
        for(int i=0;i<=position-1;i++)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

int main()
{
    node* node1 = new node(10);
    node *head=node1;
    node *tail=node1;
    insertattail(tail,12);
    insertatposition(tail,head,2,22);
    print(head);
    cout<<" head "<<head->value<<endl;
    cout<<" tail "<<tail->value<<endl;
    deletenode(head,1);
    print(head);
}
