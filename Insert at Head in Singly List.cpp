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
void insertathead(node* &head, int d)
{
    node* temp = new node(d);
    temp->next = head;
    head = temp;
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
    node* node1 = new node(20);
    node *head=node1;
    int n;
    for(int i=0;i<10;i++){
        cin>>n;
    cout<<"the list is"<<endl;
    insertathead(head, n);
    print(head);
    }
}
