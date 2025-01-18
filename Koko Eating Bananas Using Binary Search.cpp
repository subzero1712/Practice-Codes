//striver
#include<bits/stdc++.h>>

int max(vector<int>&v){
    int maxi=INT_MIN;
    for(int i=0;i<v.size();i++){
        maxi=max(maxi,v[i]);
    }
    return maxi;
}
int calc(vector<int> &v, int hours){
    long long totalH=0;
    for(int i=0;i<v.size();i++){
        totalH=totalH+ceil((double)v[i]/(double)hours);
    }
    return totalH;
}
int minimumRateToEatBananas(vector<int> v, int h) {
    int low=1;
    int high=max(v);
    while(low<=high){
        int mid=low+(high-low)/2;
        int totalH=calc(v,mid);
        if(totalH<=h){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
//leetcode
class Solution {
public:
    int maxElement(vector<int>& v) {
    int maxi = INT_MIN;
    for (int i = 0; i < v.size(); i++) {
        maxi = std::max(maxi, v[i]); // Use std::max to avoid conflict
    }
    return maxi;
}

int calc(vector<int>& v, int hours) {
    long long totalH = 0; // Use long long to handle large values
    for (int i = 0; i < v.size(); i++) {
        totalH += (v[i] + hours - 1) / hours; // Avoid floating-point operations
        if (totalH > 1e9) return totalH; // Early exit if hours exceed a limit
    }
    return totalH;
}
    int minEatingSpeed(vector<int>& v, int h) {
        int low = 1;
    int high = maxElement(v);
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int totalH = calc(v, mid);

        if (totalH <= h) {
            result = mid; // Update result for minimum rate
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
    }
};
