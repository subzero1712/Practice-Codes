class Solution {
public:
    static bool comp(vector<int> &v1, vector<int> &v2){
        return v1[1]<v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(),comp);
        int cnt=1;
        int endtime=intervals[0][1];
        for(int i=0;i<n;i++){
            if(intervals[i][0]>=endtime){
                cnt++;
                endtime=intervals[i][1];
            }
        }
        return n-cnt;
    }
};
