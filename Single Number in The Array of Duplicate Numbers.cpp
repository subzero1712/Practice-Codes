//Brute force Approach
#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums) {
    int freq[10001] = {0};
    for (int x : nums) {
        freq[x]++;
    }
    for (int x : nums) {
        if (freq[x] == 1) {
            return x;
        }
    }
    return -1;
}

//Better Approach Using Map
#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (int x : nums) {
        mp[x]++;
    }
    for (auto it : mp) {
        if (it.second == 1) {
            return it.first;
        }
    }
    return -1;
}

//Optimal Approach Using XOR
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xr=0;
        for(int i=0;i<nums.size();i++){
            xr=xr^nums[i];
        }
        return xr;
    }
};
