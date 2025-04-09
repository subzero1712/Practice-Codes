//Initialization of Linked List
class Node{
    Public: 
    int data; 
    Node* next; 
    Public:
    Node (int data1, Node* next1){
        data=data1;  
        next=next1;  
    }
    Node (int data1){
        data=data1; 
        next=nullptr;  
    }
};
int main(){
    vector<int> arr={2,5,8,7};
    Node* y= new Node(arr[0]);
    cout<<y<<'\n'; 
    cout<<y->data<<'\n';
}

//Creation of Linked List from Array
Node* convertArr2LL(vector<int> &arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;
  Node* temp = new Node(arr[i]);
  for(int i=1;i<arr.size();i++) {
    mover->next = temp;
    mover = temp;
}
return head;
}

//Traversal on Linked List
Node* temp=head;
while(!temp){
  cout<<temp<<endl;
  temp=temp->next;
}

//Length of Linked List
int cnt=0;
Node* temp=head;
while(!temp){
  cout<<temp<<endl;
  temp=temp->next;
  cnt++;
}
cout<<cnt;

//Searching in Linked List
int searchInLinkedList(Node<int> *head, int k) {
    Node<int>* temp = head;
    while (temp != NULL) {
        if (temp->data == k) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
