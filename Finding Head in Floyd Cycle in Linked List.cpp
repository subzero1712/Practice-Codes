#include <iostream>

using namespace std;
Node* floydCycle(node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    node* slow=head;
    node* fast=head;
    while(slow!=NULL && fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast)
        {
            return slow;
        }
    }
    return NULL;
}

node* getStart(node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    node* intersection=floydCycle(head);
    node* slow=head;
    while(intersection!=slow)
    {
        intersection=intersection->next;
        slow=slow->next;
    }
    return slow;
}
