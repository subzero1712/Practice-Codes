#include <iostream>
#include <string.h>
 using namespace std;
 int main()
{
  char str1[256], str2[256], *p, *q;

  cout<<"Enter the first string: ";
  gets(str1);
  cout<<"Enter the second string: ";
  gets(str2);

  p = str1;
  q = str2;


  while(*p!='\0')
    p++;


  while(*q!='\0')
  {
    *p=*q;
    q++;
    p++;
  }
  *p='\0';

  cout<<"After the concatenation: %s "<<str1;
}
