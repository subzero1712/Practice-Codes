//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    struct Node *next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// function to display the linked list
void display(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout<<endl;
}

Node* insertInMiddle(Node* head, int x);

int main()
{
    int T, n, x;
    cin>>T;
    while(T--)
    {
        cin>> n >> x;
        
        struct Node *head = new Node(x);
        struct Node *tail = head;
        
        for (int i=0; i<n-1; i++)
        {
            cin>>x;
            tail->next = new Node(x);
            tail = tail->next;
        }
        
        cin>> x;
        head = insertInMiddle(head, x);
        display(head);
    }
    return 0;
}

// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to insert a node in the middle of the linked list.
Node* insertInMiddle(Node* head, int x)
{
	Node* temp=head;
	Node* val=new Node(x);
	int cnt=0;
	while(temp!=NULL)
	{
	    cnt++;
	    temp=temp->next;
	}
	if(cnt%2==0)
	{
	    int mid=cnt/2;
	    temp=head;
	    for(int i=0;i<mid-1;i++)
	    {
	        temp=temp->next;
	    }

	}
	else
	{
	    int mid=cnt/2;
	    temp=head;
	    for(int i=0;i<mid;i++)
	    {
	        temp=temp->next;
	    }
	}
    val->next=temp->next;
    temp->next=val;
	return head;
}
