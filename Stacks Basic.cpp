#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> s;
    //push operation
    s.push(2);
    s.push(3);
    //pop operation
    s.pop();
    //top operation
    cout<<"the top element is "<<s.top()<<endl;
    //checking for emptiness
    if(s.empty())
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
        cout<<"stack is not empty"<<endl;
    }
      cout<<"size of stack "<<s.size()<<endl;

}
