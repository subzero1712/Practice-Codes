/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/
Node* tail(Node* head){
    if(head == NULL) return NULL;
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp;
}
vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Node* temp1=head;
    // vector<pair<int, int>> ans;
    // while(temp1!=NULL){
    //     Node* temp2=temp1->next;
    //     while(temp2!=NULL){
    //         if(temp1->data+temp2->data==k){
    //             ans.push_back({temp1->data,temp2->data});
    //         }
    //         temp2=temp2->next;
    //     }
    //     temp1=temp1->next;
    // }
    // return ans;

    Node* temp=head;
    Node* left=head;
    Node* right=tail(temp);
    vector<pair<int, int>> ans;
    if(head==NULL) return ans;
    while(left->data<right->data){
        if(left->data+right->data==k){
            ans.push_back({left->data,right->data});
            left=left->next;
            right=right->prev;
        }
        else if(left->data+right->data>k){
            right=right->prev;
        }
        else{
            left=left->next;
        }
    }
    return ans;
}
