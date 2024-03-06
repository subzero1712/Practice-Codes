      class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int key) {
        Node* temp=head;
        bool flag;
        while(temp!=NULL)
        {
            if(temp->data==key)
            {
                return true;
            }
            temp=temp->next;
        
        }
    }
};

