int SecondLargest(vector<int> &a, int n){
    int largest = 0;
    int slargest = -1;
    for(int i=0;i<n;i++){
        if(a[i]>largest){
            slargest = largest;
            largest = a[i];
        }
        else if(a[i]!=largest && a[i]>slargest){
            slargest = a[i];
        }
    }
    return slargest;
}
int SecondSmallest(vector<int> &arr, int n){
    int smallest = INT_MAX;
    int ssmallest = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<smallest){
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i]>smallest && arr[i]<ssmallest){
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}
vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.
    int slargest = SecondLargest(a, n);
    int ssmallest = SecondSmallest(a, n);
    return{slargest, ssmallest};
}
