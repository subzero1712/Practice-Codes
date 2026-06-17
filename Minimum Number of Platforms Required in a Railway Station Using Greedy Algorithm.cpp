//Brute Force
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPlatforms(int n, int arr[], int dep[]) {
        int ans = 1;
        for (int i = 0; i < n; i++) {
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
                    (arr[j] >= arr[i] && arr[j] <= dep[i])) {
                    count++;
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};

//Optimal Solution
#include<bits/stdc++.h>
int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at + n);
    sort(dt, dt + n);
    int cnt=0;
    int maxi=0;
    int i=0;
    int j=0;
    while(i<n && j<n){
        if(at[i]<=dt[j]){
            cnt++;
            i++;
            maxi=max(maxi,cnt);
        }
        else{
            cnt--;
            j++;
        }
    }
    return maxi;
}
