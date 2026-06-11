//Heap Method
class Solution {
public:
    typedef pair<int, char> P;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<P, vector<P>> pq; //max-heap

        if(a > 0) {
            pq.push({a, 'a'});
        }
        if(b > 0) {
            pq.push({b, 'b'});
        }
        if(c > 0) {
            pq.push({c, 'c'});
        }

        string result = "";

        while(!pq.empty()) {
            int currCount = pq.top().first;
            int currChar = pq.top().second;
            pq.pop();

            if(result.length() >= 2 && result[result.length()-1] == currChar && result[result.length()-2] == currChar) {
                //we can't use currChar. Check for next largest freqency char
                if(pq.empty()) {
                    break;
                }

                int nextCount = pq.top().first;
                int nextChar = pq.top().second;
                pq.pop();

                result.push_back(nextChar);
                nextCount--;
                if(nextCount > 0) {
                    pq.push({nextCount, nextChar});
                }
            } else {
                currCount--;
                result.push_back(currChar);
            }

            if(currCount > 0) {
                pq.push({currCount, currChar});
            }
        }

        return result;
    }
};

//Using LPS
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();

        vector<int> lps(n, 0);

        int len = 0;
        int i = 1;

        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return s.substr(0, lps[n - 1]);
    }
};

