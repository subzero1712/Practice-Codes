#include <iostream>

using namespace std;

int main()
{
    if(head==NULL)
    {
        return NULL;
    }
    node* curr=head;
    while(curr!=NULL)
    {
        if((curr->next!=NULL) && (curr->data==curr->next->data))
        {
            node* nextnode=curr->next->next;
            node* nodetodelete=curr->next;
            delete(nodetodelete);
            curr->next=nextnode;
        }
        else
        {
            curr=curr->next;
        }
    }
    return head;
}
