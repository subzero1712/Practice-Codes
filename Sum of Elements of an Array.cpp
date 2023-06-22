#include <iostream>

using namespace std;

int arrsum( int num[], int size)
{
    int i;
    int sum=0;
    for(i=0;i<size;i++){
        sum = sum + num[i];
    }
    return sum;
    
}
int main()
{
    int i;
    int size;
    cin>>size;
    int num[10];
    for(i=0;i<size;i++){
        cin>>num[i];
        
    }
    cout<<"the sum of the  elements of the  array is "<< arrsum(num, size);
}
 

