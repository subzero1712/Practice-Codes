// Node* rev(Node* head){
//     if(head==NULL || head->next==NULL){
//         return head;
//     }
//     Node* newHead = rev(head->next);
//     Node* front = head->next;
//     front->next = head;
//     head->next = NULL;
//     return newHead;
// }

//Recursive
int helper(Node* temp){
    if(temp==NULL){
        return 1;
    }
    int carry=helper(temp->next);
    temp->data+=carry;
    if(temp->data<10){
        return 0;
    }
    temp->data=0;
    return 1;
}
Node *addOne(Node *head)
{
    //Non-Recursive
    // Node* temp = rev(head);
    // int carry = 1;

    // Node* curr = temp;
    // while(curr != NULL){
    //     curr->data += carry;
    //     if(curr->data < 10){
    //         carry = 0;
    //         break;
    //     } else {
    //         curr->data = 0;
    //         carry = 1;
    //     }
    //     curr = curr->next;
    // }
    // head = rev(temp);
    // if(carry == 1){
    //     Node* newNode = new Node(1);
    //     newNode->next = head;
    //     return newNode;
    // }
    // return head;

    int carry=helper(head);
    if(carry == 1){
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}
