#include <iostream>

using namespace std;
class node{
    public:
    int data;
    node* prev;
    node* next;
    
    node(int d)
    {
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
};
void print(node* &head)
{
    if(head == NULL)
    {
        cout<<"empty list"<<endl;
    }
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int getlength(node* &head)
{
    int len=0;
    node* temp=head;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    return len;
}

void inserthead(node* &head, int d)
{
    node* temp=new node(d);
    temp->next=head;
    head->prev=temp;
    head = temp;
    head->prev=NULL;
}

void inserttail(node* &tail, int d)
{
    node* temp=new node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void insertposition(node* &tail, node* &head,int position, int d)
{
    node* nodetoinsert = new node(d);
    if(position==1){
        inserthead(head,d);
        return;
    }
     int cnt=1;
     node* temp=head;
     while(cnt<position-1)
     {
        temp=temp->next;
        cnt++;
     }
     if(temp->next==NULL)
     {
        inserttail(tail,d);
        return;
     }
     nodetoinsert->next=temp->next;
     (temp->next)->prev=nodetoinsert;
     temp->next=nodetoinsert;
     nodetoinsert->prev=temp;
     
}
int main()
{
    node* node1= new node(10);
    node* head=node1;
    node* tail=node1;
    print(head);
    //cout<<getlength(head)<<endl;
    inserthead(head,11);
    inserthead(head,45);
    inserttail(tail,56);
    print(head);
    insertposition(tail,head,2,78);
    print(head);
}
