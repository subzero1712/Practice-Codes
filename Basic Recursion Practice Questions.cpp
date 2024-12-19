//Print 1 to N Using Recursion
class Solution {
  public:
    // Complete this function
    void printNos(int n,int i=1) {
   
        if(i>n){
            return;
        }
        cout<<i<<" ";
        printNos(n,i+1);
    }
};

//Print N to 1 Using Recursion
class Solution {
  public:
    void printNos(int N) {
        if(N<1){
            return;
        }
        cout<<N<<" ";
        printNos(N-1);
    }
};

//Print Name N Times
class Solution {
  public:
    void printGfg(int N, int i=1) {
        if(i>N){
            return;
        }
        cout<<"GFG"<<" ";
        printGfg(N,i+1);
    }
};

//Sum of First N Numbers
class Solution {
  public:
    int sumOfSeries(int n) {
        if(n==0){
            return 0;
        }
//sum of series 1^3+2^3...N^3
        return pow(n,3)+sumOfSeries(n-1);
    }
};

//Factorial of a Number Using Recursion
int fact(int n){
  if(n==0) return 1;
  return n*fact(n-1);
}

//Reverse an Array Using Recursion
  //1st Approach
  int reverse(vector<int> &arr, int l,int r){
    if(l>=r) return;
    swap(arr[l], arr[r]);
    reverse(l+1,r-1);
  }
  //2nd Approach
  class Solution {
  public:
    void reverseArray(vector<int> &arr, int i=0) {
        if(i>=arr.size()/2){
            return;
        }
        swap(arr[i],arr[n-i-1]);
        reverseArry(arr,i+1);
    }
};

//Check Palindrome Using Recursion
int func(int i){
  if(i>=n/2){
    return true;
  }
  if(s[i]!=s[n-i-1]){
    return false;
  }
  return func(i+1);
}

//Fibonacci Using Recursion
class Solution {
public:
    int fib(int n) {
        if(n==1){
            return 1;
        }
        if(n==0){
            return 0;
        }
        return fib(n-1)+fib(n-2);
    }
};

