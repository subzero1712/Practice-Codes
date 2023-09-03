#include <iostream>

using namespace std;

void reverse(string &str, int i, int j)
{
    if(i>j)
    {
        return;
    }
    int temp=str[i];
    str[i]=str[j];
    str[j]=temp;
    i++;
    j--;
    reverse(str,i,j);
}
int main()
{
    string name="palak is best";
    reverse(name,0,name.length()-1);
    cout << name << endl;
}
