
class Solution
{
    private:
    void inserttail(Node* &head, Node* &tail, int val)
    {
        Node* temp=new Node(val);
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            return;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
    Node* reverse(Node*  head)
    {
        Node* curr=head;
        Node* prev=NULL;
        Node* next=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    struct Node* add(Node* &first, Node* &second)
    {
        int carry=0;
        Node* ansHead=NULL;
        Node* ansTail=NULL;
        while(first!=NULL && second!=NULL)
        {
            int sum=carry+first->data+second->data;
            int digit=sum%10;
            inserttail(ansHead, ansTail,digit);
            carry=sum/10;
            first=first->next;
            second=second->next;
        }
        while(first!=NULL)
        {
            int sum=carry+first->data;
            int digit=sum%10;
            inserttail(ansHead,ansTail,digit);
            carry=sum/10;
            first=first->next;
        }
        while(second!=NULL)
        {
            int sum=carry+second->data;
            int digit=sum%10;
            inserttail(ansHead,ansTail,digit);
            carry=sum/10;
            second=second->next;
        }
        while(carry!=0)
        {
            int sum=carry;
            int digit=sum%10;
            inserttail(ansHead,ansTail,digit);
            carry=sum/10;
        }
        return ansHead;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first=reverse(first);
        second=reverse(second);
        Node* ans=add(first,second);
        ans=reverse(ans);
        return ans;
    }
};

//2nd Approach
class Solution
{
    private:
    void inserttail(Node* &head, Node* &tail, int val)
    {
        Node* temp=new Node(val);
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            return;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
    Node* reverse(Node*  head)
    {
        Node* curr=head;
        Node* prev=NULL;
        Node* next=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    struct Node* add(Node* &first, Node* &second)
    {
        int carry=0;
        Node* ansHead=NULL;
        Node* ansTail=NULL;
        while(first!=NULL || second!=NULL || carry!=0)
        {
            int val1=0;
            if(first!=NULL)
            {
                val1=first->data;
            }
            int val2=0;
            if(second!=NULL)
            {
                val2=second->data;
            }
            
            
            
            int sum=carry+val1+val2;
            int digit=sum%10;
            inserttail(ansHead, ansTail,digit);
            carry=sum/10;
            if(first!=NULL){
            first=first->next;
            }
            if(second!=NULL){
            second=second->next;
            }
        }
        
        return ansHead;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first=reverse(first);
        second=reverse(second);
        Node* ans=add(first,second);
        ans=reverse(ans);
        return ans;
    }
};
