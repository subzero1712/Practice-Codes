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
    tail = tail->next;;
    
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

int main()
{
    node* node1 = new node(NULL);
    node *head=node1;
    node *tail=node1;
    int n;//,position=2;
    for(int i=0;i<5;i++){
        cin>>n;
    cout<<"the list is"<<endl;
    insertattail(tail, n);
    print(head);
    }
}
