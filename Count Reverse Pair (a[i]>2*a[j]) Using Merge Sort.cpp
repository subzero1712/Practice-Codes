void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[i] > 2 * arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += countPairs(arr, low, mid, high); //Modification
    merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

//leetcode
class Solution {
public:
void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> temp; // Temporary array
    int left = low;   // Starting index of left half of nums
    int right = mid + 1; // Starting index of right half of nums

    // Storing elements in the temporary array in sorted order
    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        } else {
            temp.push_back(nums[right]);
            right++;
        }
    }

    // If elements on the left half are still left
    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }

    // If elements on the right half are still left
    while (right <= high) {
        temp.push_back(nums[right]);
        right++;
    }

    // Transfer all elements from the temporary array back to the original array
    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
}

int countPairs(vector<int>& nums, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;

    for (int i = low; i <= mid; i++) {
        while (right <= high && static_cast<long long>(nums[i]) > 2LL * nums[right]) {
            right++;
        }
        cnt += (right - (mid + 1));
    }

    return cnt;
}

int mergeSort(vector<int>& nums, int low, int high) {
    if (low >= high) return 0; // Base case

    int mid = low + (high - low) / 2; // Avoid overflow
    int cnt = 0;

    cnt += mergeSort(nums, low, mid);     // Sort left half
    cnt += mergeSort(nums, mid + 1, high); // Sort right half
    cnt += countPairs(nums, low, mid, high); // Count reverse pairs
    merge(nums, low, mid, high);          // Merge sorted halves

    return cnt;
}
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};

int team(vector <int> & skill, int n)
{
    return mergeSort(skill, 0, n - 1);
}
