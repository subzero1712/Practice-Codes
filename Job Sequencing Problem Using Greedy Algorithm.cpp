#include<bits/stdc++.h>
bool comp(vector<int>& a, vector<int>& b){
    return a[2] > b[2];   
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), comp);
    int maxDeadline = 0;
    for(auto &job : jobs)
        maxDeadline = max(maxDeadline, job[1]);
    vector<int> slot(maxDeadline + 1, -1);
    int cnt = 0;
    int totprofit = 0;
    for(int i = 0; i < jobs.size(); i++)
    {
        int deadline = jobs[i][1];
        int profit   = jobs[i][2];
        for(int j = deadline; j >= 1; j--)
        {
            if(slot[j] == -1)
            {
                slot[j] = jobs[i][0];
                cnt++;
                totprofit += profit;
                break;
            }
        }
    }

    return {cnt, totprofit};
}
