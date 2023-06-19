#include <iostream>

using namespace std;

int
main ()
{
  double farhen;
  double celcius;
  cout << "enter temperature in farhenhiet" << endl;
  cin >> farhen;
  celcius = 5 * (farhen - 32) / 9;
  cout << "the temperature in celcius is" << celcius;
  return 0;
}

