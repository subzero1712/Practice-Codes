#include <iostream>

using namespace std;
class node{
  public:
  int data;
  node *next;
  
  node(int data)
  {
      this->data=data;
      this->next=NULL;
  }
  ~node()
  {
      int value = this->data;
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
    if(head==NULL)
    {
        cout<<"empty LL "<<endl;
    }
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
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
    if(position==1)
    {
        insertathead(head,d);
        return;
    }
    node* temp=head;
    
    int count=1;
    while(count<position-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL)
    {
        insertattail(tail,d);
        return;
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
        int cnt=1;
        node* curr=head;
        node* prev=NULL;
        while(cnt<position)
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
    //print(head);
    insertattail(tail,12);
    //print(head);
    insertattail(tail,15);
    //print(head);
    insertatposition(tail,head,4,22);
    print(head);
    cout<<" head "<<head->data<<endl;
    cout<<" tail "<<tail->data<<endl;
    deletenode(head,4);
    print(head);
    cout<<" head "<<head->data<<endl;
    cout<<" tail "<<tail->data<<endl;
   
}

