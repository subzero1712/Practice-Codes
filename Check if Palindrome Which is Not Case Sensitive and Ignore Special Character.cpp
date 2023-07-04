#include <bits/stdc++.h> 
string low(string str)
{
    char n[100000];
    int i = 0,k=0;
    while(str[i]!='\0')
    {
        char a = str[i];
        if(a>=65 && a<=90)
            n[k++] = a+32;
        if(a>=97 && a<=122)
            n[k++] = a;
        if(a>=48 && a<=57)
            n[k++] = a;
        i++;
    }
    n[k] = '\0';
    return n;
}
int length(string str)
{
    int i = -1;
    while(str[++i]!='\0');
    return i;
}
string rev(string str)
{
    int l = length(str);
    for(int i = 0; i < l/2 ; i++)
  {
    int a = str[i];
    str[i] = str[l-i-1];
    str[l-i-1] = a;
  }
    return str;
}
  

bool checkPalindrome(string sl)
{
    // Write your code here.
    string lowered = low(sl);
    string reversed = rev(lowered);
    return lowered==reversed;
}
