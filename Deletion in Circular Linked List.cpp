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
void deletenode(node* &tail,int d)
{
    if(tail==NULL)
    {
        cout<<"empty linked list, please check again"<<endl;
        return;
    }
    else
    {
        node* prev=tail;
        node* curr=prev->next;
        while(curr->data!=d)
        {
            prev=curr;
            curr=curr->next;
        }
        
        prev->next=curr->next;
        if(curr==prev) //for single element in linked list
        {
            tail=NULL;
        }
        if(tail==curr) //tail update nahi hora tha to node ke delete hone par tail ka pata nahi rehta 
        {
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
        
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
    //node* node1=new node(5);
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
    deletenode(tail,3);
    print(tail);
    deletenode(tail,2);
    print(tail);
}






