#include<iostream>
using namespace std;
int
main ()
{
  char user_input;
  cin >> user_input;
  int ascii = user_input;
  if (ascii >= 65 && ascii <= 90)
    {
      cout << "the entered character is uppercase" << " " << user_input <<
	endl;

    }
  else if (ascii >= 97 && ascii <= 122)
    {
      cout << "the entered character is lowercase" << " " << user_input <<
	endl;
    }
  else if (ascii >= 48 && ascii <=57)
    {
      cout << "it is a numeric value" << " " << user_input << endl;

    }
  else
    {
      cout << "it is a special character" << " " << user_input << endl;
    }
  return 0;
}



