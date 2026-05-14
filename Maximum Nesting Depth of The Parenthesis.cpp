class Solution {
public:
    int maxDepth(string s) {
        int res=0;
        int curr=0;
        for(char& c:s){
            if(c=='('){
                curr++;
                res=max(res,curr);
            }
            else if(c==')'){
                curr--;
            }
        }
        return res;
    }
};
