//1st Approach
class Solution
{
    private:
    void inserttail(Node* &head, Node* &tail, int data)
    {
        Node* newnode=new Node(data);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=tail->next;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        Node* clonehead=NULL;
        Node* clonetail=NULL;
        Node* temp=head;
        while(temp!=NULL)
        {
            inserttail(clonehead, clonetail, temp->data);
            temp=temp->next;
        }
        
        unordered_map<Node*,Node*> oldtonew;
        Node* originalnode=head;
        Node* clonenode=clonehead;
        while(originalnode!=NULL && clonenode!=NULL){
        oldtonew[originalnode]=clonenode;
        originalnode=originalnode->next;
        clonenode=clonenode->next;
        }
        originalnode=head;
        clonenode=clonehead;
        while(originalnode!=NULL)
        {
            clonenode->arb=oldtonew[originalnode->arb];
            originalnode=originalnode->next;
            clonenode=clonenode->next;
        }
        return clonehead;
    }

};

//2nd Approach
class Solution
{
    private:
    void inserttail(Node* &head, Node* &tail, int data)
    {
        Node* newnode=new Node(data);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        Node* clonehead=NULL;
        Node* clonetail=NULL;
        Node* temp=head;
        while(temp!=NULL)
        {
            inserttail(clonehead, clonetail, temp->data);
            temp=temp->next;
        }
        Node* originalnode=head;
        Node* clonenode=clonehead;
        
        while(originalnode!=NULL && clonenode!=NULL)
        {
            Node* next=originalnode->next;
            originalnode->next=clonenode;
            originalnode=next;
            
            next=clonenode->next;
            clonenode->next=originalnode;
            clonenode=next;
        }
         temp=head;
        while(temp!=NULL)
        {
            if(temp->next!=NULL)
            {
                temp->next->arb=temp->arb ? temp->arb->next:temp->arb;
            }
            temp=temp->next->next;
        }
        originalnode=head;
        clonenode=clonehead;
        while(originalnode!=NULL)
        {
            originalnode->next=clonenode->next;
            originalnode=originalnode->next;
            
            if(originalnode!=NULL){
            clonenode->next=originalnode->next;
            }
            clonenode=clonenode->next;
        }
        return clonehead;
    }
    

};
