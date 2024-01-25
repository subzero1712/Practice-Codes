#include <iostream>
#include<map>
using namespace std;
bool detectLoop(node* head)
{
    if(head==NULL)
    {
        return false;
    }
    map<node*, bool> visited;
    node* temp=head;
    while(temp!=NULL)
    {
        if(visited[temp]==true)
        {
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}
