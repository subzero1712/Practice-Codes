//using lowerbound and upperbound
int lowerBound(const vector<int>& arr, int n, int x) {  
    int low = 0;     
    int high = n - 1;     
    int ans = n;     
    while (low <= high) {         
        int mid = low + (high - low) / 2;         
        if (arr[mid] >= x) {             
            ans = mid;             
            high = mid - 1;         
        } else {             
            low = mid + 1;         
        }     
    }     
    return ans; 
} 

int upperBound(const vector<int>& arr, int n, int x) {  
    int low = 0;     
    int high = n - 1;     
    int ans = n;     
    while (low <= high) {         
        int mid = low + (high - low) / 2;         
        if (arr[mid] > x) {             
            ans = mid;             
            high = mid - 1;         
        } else {             
            low = mid + 1;         
        }     
    }     
    return ans; 
} 

pair<int, int> firstAndLastPosition(const vector<int>& arr, int n, int k) {     
    int lb = lowerBound(arr, n, k);     
    if (lb == n || arr[lb] != k) {         
        return {-1, -1};     
    }     
    return {lb, upperBound(arr, n, k) - 1}; 
}

//using direct binary search
int first(vector<int> &arr, int n, int k){
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==k){
            ans=mid;
            high=mid-1;
        }
        else if(arr[mid]<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int last(vector<int> &arr, int n, int k){
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==k){
            ans=mid;
            low=mid+1;
        }
        else if(arr[mid]<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    return {first(arr,n,k),last(arr,n,k)};
}
