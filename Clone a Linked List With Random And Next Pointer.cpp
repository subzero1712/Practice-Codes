class Solution {
public:
    Node* copyRandomList(Node* head) {
        // if(head == NULL) return NULL;

        // unordered_map<Node*, Node*> mp;

        // Node* temp = head;
        // while(temp != NULL){
        //     mp[temp] = new Node(temp->val);
        //     temp = temp->next;
        // }
        // temp = head;
        // while(temp != NULL){
        //     mp[temp]->next = mp[temp->next];
        //     mp[temp]->random = mp[temp->random];
        //     temp = temp->next;
        // }
        // return mp[head];

        Node* temp=head;
        while(temp!=NULL){
            Node* copyNode=new Node(temp->val);
            copyNode->next=temp->next;
            temp->next=copyNode;
            temp=temp->next->next;
        }

        temp=head;
        while(temp!=NULL){
            Node* copyNode=temp->next;
            if(temp->random!=NULL) copyNode->random=temp->random->next;
            temp=temp->next->next;
        }

        temp = head;
        Node* dummy = new Node(-1);
        Node* copyTail = dummy;

        while(temp != NULL){
            Node* copy = temp->next;

            copyTail->next = copy;
            copyTail = copy;

            temp->next = copy->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};
