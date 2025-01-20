#include "bits/stdc++.h"
int func(vector<int> &arr,int pages){
    int studcnt=1;
    int pagesstud=0;
    for(int i=0;i<arr.size();i++){
        if(pagesstud+arr[i]<=pages){
            pagesstud+=arr[i];
        }
        else{
            studcnt++;
            pagesstud=arr[i];
        }
    }
    return studcnt;

}
int findMaxElement(vector<int> &arr, int size) {
    int maxElement = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    return maxElement;
}
int sumVector(vector<int>& vec) {
    int sum = 0;
    for (int num : vec) {
        sum += num;
    }
    return sum;
}
int findPages(vector<int>& arr, int n, int m) {
    int low=findMaxElement(arr,n);
    int high=sumVector(arr);
    if(m>n) return -1;
    int pages=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(func(arr, mid)>m){
            low=mid+1;
        }
        else{
            pages=mid;
            high=mid-1;
        }
    }
    return pages;

}
