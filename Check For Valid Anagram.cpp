//Brute force Approach
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t) return true;
        return false;
    }
};

//Better approach
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        
        map<int,int> h1,h2;

        for(int i=0;i<s.size();i++){
            h1[s[i]]++;
            h2[t[i]]++;
        }

        if(h1==h2) return true;
        
        return false;
    }
};

//Optimal Approach
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        map<int,int> h1;
        for(int i=0;i<s.length();i++){
            h1[s[i]]++;
            h1[t[i]]--;
        }
        for(auto p : h1){
            if(p.second != 0){
                return false;
            }
        }
        return true;
    }
};
