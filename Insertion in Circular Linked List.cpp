#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    
    node(int data)
    {
        this->data=data;
        this->next=NULL;
        
    }
    ~node()
    {
        int value=this->data;
        if(next!=NULL)
        {
            delete next;
            next=NULL;
        }
        cout<<"memory free for "<<value<<endl;
    }
};
void insertnode(node* &tail, int element, int d)
{
    if(tail==NULL)
    {
        node* newnode=new node(d);
        tail=newnode;
        newnode->next=newnode;
        
    }
    else{
    node* curr=tail;
    while(curr->data != element)
    {
        curr=curr->next;
    }
    node* temp=new node(d);
    temp->next=curr->next;
    curr->next=temp;
    }
}
void print(node* &tail)
{
    node* temp=tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
    
    cout<<endl;
}
int main()
{
    node* node1=new node(5);
    node* tail=NULL;
    insertnode(tail,5,3);
    print(tail);
    insertnode(tail,3,5);
    print(tail);
    insertnode(tail,5,7);
    print(tail);
    insertnode(tail,7,9);
    print(tail);
    insertnode(tail,5,6);
    print(tail);
}






