#include <iostream>

using namespace std;
char tolowercase(char ch)
{
    if(ch>='a' && ch<='z')
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
    
}

bool checkpalindrome(char ch[], int n)
{
    int s=0;
    int e=n - 1;
    while(s<=e)
    {
        if(tolowercase(ch[s])!=tolowercase(ch[e]))
        {
            return false;
        }
        else
        {
            s++;
            e--;
        }
        
    }
    return true;
}
int getlength(char a[])
{
    int count = 0;
    for(int i = 1; a[i]!=0; i++)
    {
        count++;
    }
    return count;
}
int main()
{
    char ch[20];
    cout<<"enter the word ";
    cin>>ch;
    int len = getlength(ch);
    cout<<"palindrome or not "<<checkpalindrome(ch, len);
}
