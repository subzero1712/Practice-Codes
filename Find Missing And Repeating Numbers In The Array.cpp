//Better Approach
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    int n=a.size();
    int hash[n+1]={0};
    for(int i=0;i<n;i++){
        hash[a[i]]++;
    }
    int repeating=-1;
    int missing=-1;
    for(int i=1;i<=n;i++){
        if(hash[i]==2) repeating=i;
        else if(hash[i]==0) missing=i;
        if(repeating!=-1 && missing!=-1){
            break;
        }
    }
    return {repeating, missing};
}
//Optimal1 Approach
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    long long n=a.size();
    long long sn=(n*(n+1))/2;
    long long s2n=(n*(n+1)*(2*n+1))/6;
    long long s=0;
    long long s2=0;
    for(int i=0;i<n;i++){
         s+=a[i];
         s2+=(long long)a[i]*(long long)a[i];
    }
    long long val1=s-sn;
    long long val2=s2-s2n;
    val2=val2/val1;
    long long x=(val1+val2)/2;
    long long y=x-val1;
    return{(int)x, (int)y};
}
//Optimal2 Approach
#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size(); // size of the array

    int xr = 0;

    //Step 1: Find XOR of all elements:
    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }

    //Step 2: Find the differentiating bit number:
    int number = (xr & ~(xr - 1));

    //Step 3: Group the numbers:
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
        //part of 1 group:
        if ((a[i] & number) != 0) {
            one = one ^ a[i];
        }
        //part of 0 group:
        else {
            zero = zero ^ a[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        //part of 1 group:
        if ((i & number) != 0) {
            one = one ^ i;
        }
        //part of 0 group:
        else {
            zero = zero ^ i;
        }
    }

    // Last step: Identify the numbers:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == zero) cnt++;
    }

    if (cnt == 2) return {zero, one};
    return {one, zero};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}
