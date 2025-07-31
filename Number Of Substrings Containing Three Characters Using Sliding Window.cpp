//Brute Force Approach
class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            unordered_map<int,int> mpp;
            for(int j=i;j<n;j++){
                mpp[s[j]-'a']=1;
                if(mpp[0]+mpp[1]+mpp[2]==3){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//Simple Optimisation Of Brute Force Approach
class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            unordered_map<int,int> mpp;
            for(int j=i;j<n;j++){
                mpp[s[j]-'a']=1;
                if(mpp[0]+mpp[1]+mpp[2]==3){
                    cnt=cnt+(n-j);
                    break;
                }
            }
        }
        return cnt;
    }
};

//Sliding Window Approach
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int lastseen[3]={-1,-1,-1};
        int cnt=0;
        for(int i=0;i<n;i++){
            lastseen[s[i]-'a']=i;
            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
                cnt=cnt+(1+min(lastseen[0],min(lastseen[1],lastseen[2])));
            }
        }
        return cnt;
    }
};
