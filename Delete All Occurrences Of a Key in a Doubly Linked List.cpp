/**
 * Definition of doubly linked list:
 *
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
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * deleteAllOccurrences(Node* head, int k) {
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==k){
            Node* curr=temp;
            Node* nextNode=temp->next;
            if(temp==head){
                head=head->next;
            }
            if(curr->prev!=NULL){
                curr->prev->next=curr->next;
            }
            if(curr->next!=NULL){
                curr->next->prev=curr->prev;
            }
            delete curr;
            temp=temp->next;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}
