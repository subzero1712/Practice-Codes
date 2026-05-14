//Brute Force Approach
class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(128,0);
        for(auto ch:s) freq[ch]++;
        auto cmp=[&](char a, char b){
            if(freq[a]==freq[b]) return a<b;
            return freq[a]>freq[b];
        };
        sort(s.begin(),s.end(),cmp);
        return s;
    }
};

//Better Approach
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;

        for(auto ch : s){
            freq[ch]++;
        }

        vector<pair<char,int>> freqArr;

        for(auto [ch,fq] : freq){
            freqArr.push_back({ch,fq});
        }

        auto cmp = [&](pair<char,int> &a, pair<char,int> &b){
            return a.second > b.second;
        };

        sort(freqArr.begin(), freqArr.end(), cmp);
        string ans = "";
        for(auto it : freqArr){
            ans += string(it.second, it.first);
        }
        return ans;
    }
};

//Optimal Approach Using Bucket Sort
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;

        for(auto ch : s){
            freq[ch]++;
        }
        vector<vector<char>> bucket(s.length()+1);
        for(auto [ch,fq]:freq){
            bucket[fq].push_back(ch);
        }

        string ans="";
        for(int i=s.length();i>=1;i--){
            for(auto ch:bucket[i]){
                ans.append(i,ch);
            }
        }
        return ans;
    }
};
