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
    ~node()
    {
        int value=this->data;
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"memory free with value "<<value<<endl;
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

void inserthead(node* &tail, node* &head, int d)
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

void inserttail(node* &head,node* &tail, int d)
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

void insertposition(node* &tail, node* &head,int position, int d)
{
    node* nodetoinsert = new node(d);
    if(position==1){
        inserthead(tail,head,d);
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
        inserttail(head,tail,d);
        return;
     }
     nodetoinsert->next=temp->next;
     (temp->next)->prev=nodetoinsert;
     temp->next=nodetoinsert;
     nodetoinsert->prev=temp;
     
}
void deletenode(node* &head, int position)
{
    if(position==1)
    {
        node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        node* curr=head;
        node* prev=NULL;
        int cnt=1;
        while(cnt<position)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        
        delete curr;
    }
}
int main()
{
    node* node1= new node(10);
    node* head=node1;
    node* tail=node1;
    inserthead(tail,head,11);
    inserthead(tail,head,45);
    inserttail(head,tail,56);
    print(head);
    insertposition(tail,head,3,78);
    print(head);
    cout<<getlength(head)<<endl;
    deletenode(head, 5);
    print(head);
}
