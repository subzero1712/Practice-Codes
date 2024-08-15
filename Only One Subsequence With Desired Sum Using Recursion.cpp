#include<iostream>
#include<vector>
using namespace std;

bool printS(int ind, vector <int> &ds, int s, int sum, int arr[], int n){
  if(ind==n){
    if(s==sum){
      for(auto i : ds){
        cout<<i<<" ";
      }
      cout<<endl;
      return true;
    }
    else return false;
  }
  ds.push_back(arr[ind]);
  s+=arr[ind];
  if(printS(ind+1, ds,s,sum,arr,n) == true){
    //no further recursion calls
    return true;
  }
  s-=arr[ind];
  ds.pop_back();
  if(printS(ind+1, ds, s, sum, arr, n) == true) 
  {
    return true;
  }

  return false;

}
int main(){
  int arr[] = {1,2,1};
  int n = 3;
  int sum = 2;
  vector<int> ds;
  printS(0,ds,0,sum,arr,n);
  return 0;
}
