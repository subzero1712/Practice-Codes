//Optimal
#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &A, int n, vector<int> &B, int m)
{
	// Write your code here.
	int i = 0, j = 0;
	vector<int> ans;
    while (i < A.size() && j < B.size()) {
        if (A[i] == B[j]) {
            ans.push_back(A[i]);
            i++;
            j++;
        } else if (A[i] < B[j]) {
            i++;
        } else {
            j++;
        }
    }
    return ans;
} 
//Brute
#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &A, int n, vector<int> &B, int m)
{
	// Write your code here.
	vector<int> ans;
	int vis[m]={0};
	for(int i = 0;i<n;i++){
		for(int j=0;j<m;j++){
			if(A[i]==B[j] && vis[j]==0){
				ans.push_back(A[i]);
				vis[j]=1;
				break;
			}
			if(B[j]>A[i]){
				break;
			}
		}
	}
	return ans;
}
