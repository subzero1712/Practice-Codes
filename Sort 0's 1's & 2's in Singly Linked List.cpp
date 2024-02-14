//1st Approach
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


Node* sortList(Node *head){
    
    int zerocount=0;
    int onecount=0;
    int twocount=0;

    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==0)
        {
            zerocount++;
        }
        else if(temp->data==1)
        {
            onecount++;
        }
        else if(temp->data==2)
        {
            twocount++;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL)
    {
        if(zerocount != 0)
        {
            temp->data = 0;
            zerocount--;
        }
        else if(onecount != 0)
        {
            temp->data=1;
            onecount--;
        }
        else if(twocount != 0)
        {
            temp->data=2;
            twocount--;
        }
        temp=temp->next;
    }
    return head;
}

//2nd Approach
void populate(Node* &tail, Node* curr)
{
    tail->next=curr;
    tail=curr;
}
Node* sortList(Node *head){
    Node* zerohead = new Node(-1);
    Node* zerotail = zerohead;
    Node* onehead = new Node(-1);
    Node* onetail = onehead;
    Node* twohead = new Node(-1);
    Node* twotail = twohead;

    Node* curr = head;
    while(curr!=NULL)
    {
        int value=curr->data;
        if(value==0)
        {
            populate(zerotail,curr);
        }
        else if(value==1)
        {
            populate(onetail, curr);
        }
        else if(value==2)
        {
            populate(twotail,curr);
        }
        curr=curr->next;
    }

    if(onehead->next!=NULL)
    {
        zerotail->next=onehead->next;
    }
    else
    {
        zerotail->next=twohead->next;
    }
    onetail->next=twohead->next;
    twotail->next=NULL;
    head=zerohead->next;
     
    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}
