#include<iostream>
#include<vector>
using namespace std;

int printS(int ind, int s, int sum, int arr[], int n){
  //condition not satisfied
  //strictly done if array contains positive numbers
  if(s>sum) return 0;
  if(ind==n){
    if(s==sum){
      return 1;
    }
    else return 0;
  }
  
  s+=arr[ind];
  int l = printS(ind+1,s,sum,arr,n);
  s-=arr[ind];
  int r = printS(ind+1,s,sum,arr,n);
  
  //this will send the sum to the previous step and addition/counting will continue till it reaches to the top of the recursive tree and all that sum will be returned as count
  return l + r;

}
int main(){
  int arr[] = {1,2,1,1};
  int n = 4;
  int sum = 2;
  cout<<printS(0,0,sum,arr,n);
  return 0;
}
