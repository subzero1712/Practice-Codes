#include <bits/stdc++.h> 
using namespace std;

bool palindrome(string str, int start, int end)
{ 
	if (start > end)
	{  
		return true; 
	
	}
	if (str[start] != str[end])
	{  
		return false; 
    } 
	 return palindrome(str, ++start, --end); 
}
 
void binaryToStr(string &str, long long n)
{
         if (n == 0)
		{
            return;
        }
         str += to_string(n % 2);
         binaryToStr(str, n / 2);
}
bool checkPalindrome(long long N)
{
	string str=""; 
	binaryToStr(str, N);

    return palindrome(str, 0, str.size()-1); 
}
