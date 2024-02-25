#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str="palak";
    stack<char> s;
    
    for(int i=0; i<str.length();i++)
    {
        char a=str[i];
        s.push(a);
    }
    
    string ans="";
    
    while(!s.empty())
    {
        char ch=s.top();
        ans.push_back(ch);
        s.pop();
    }
    cout<<ans;
}
