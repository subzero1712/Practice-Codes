#include <iostream>

using namespace std;
bool checkpalindrome(string &str,int i, int j)
{
    if(i>j)
    {
        return true;
    }
    if(str[i]!=str[j])
    {
        return false;
    }
    else
    {
        checkpalindrome(str,i+1,j-1);
    }
    
    
}
int main()
{
    string str="boy";
    bool ispalindrome=checkpalindrome(str,0,str.length() - 1);
    if(ispalindrome)
    {
        cout<<"it is a palindrome "<<endl;
    }
    else
    {
        cout<<"not a palindrome "<<endl;
    }
    
    
}
    
