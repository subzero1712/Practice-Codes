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
    if(head==NULL)
    {
        node* temp=new node(d);
        head=temp;
        tail=temp;
    }
    else{
        node* temp=new node(d);
        temp->next=head;
        head->prev=temp;
        head = temp;
        head->prev=NULL;
    }
}

void inserttail(node* &tail, int d)
{
    if(tail==NULL)
    {
        node* temp=new node(d);
        tail=temp;
        head=temp;
    }
    else{
        node* temp=new node(d);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
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
}
