//Brute Force Approach
class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if(s.length()!=goal.length()) return false;
        
        string temp = s;

        for(int i=0;i<s.size();i++){
            rotate(temp.begin(), temp.begin()+1, temp.end());
            
            if(temp==goal) return true;
        }

        return s==goal;
    }
};

//Optimal Approach
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        if((s+s).find(goal)!= string::npos){
            return true;
        }
        return false;
    }
};
