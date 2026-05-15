//Brute Force Approach
class Solution {
public:
    int beautySum(string s) {

        int n = s.size();
        int sumOfBeauty = 0;

        for ( int i=0; i<n; i++ ) {
            for ( int j=i; j<n; j++ ) {
                vector<int> freq(26, 0);
                for ( int k=i; k<=j; k++ ) {
                    freq[s[k] - 'a']++;
                }
                int maxi = INT_MIN, mini = INT_MAX;
                for ( int i=0; i<26; i++ ) {
                    if (freq[i] == 0 ) continue; 
                    maxi = max(maxi, freq[i]);
                    mini = min(mini, freq[i]);
                }
                sumOfBeauty += (maxi - mini);
            }
        }

        return sumOfBeauty;

    }
};

//Better Approach
class Solution {
public:
    int beautySum(string s) {

        int n = s.size();
        int sumOfBeauty = 0;

        vector<vector<int>> freq (26, vector<int>(n, 0) );

        for ( int i=0; i<n; i++ ) {
            for ( int ch=0; ch<26; ch++ ) {
                freq[ch][i] = (i>0) ? freq[ch][i-1] : 0;
            }
            freq[s[i] - 'a'][i]++;
        }

        for ( int i=0; i<n; i++ ) {
            for ( int j=i; j<n; j++ ) {
                int maxi = INT_MIN, mini = INT_MAX;

                for ( int ch=0; ch<26; ch++ ) {
                    int diff = freq[ch][j] - ( (i>0) ? freq[ch][i-1] : 0 );
                    if ( diff > 0 ) {
                        maxi = max ( maxi, diff );
                        mini = min ( mini, diff );
                    }
                }
                
                sumOfBeauty += (maxi - mini);
            }
        }

        return sumOfBeauty;

    }
};

//Optimal Approach
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sumOfBeauty = 0;
        for ( int i=0; i<n; i++ ) {
            vector<int> freq(26, 0);
            for ( int j=i; j<n; j++ ) {
                freq[s[j] - 'a']++;
                int maxi = INT_MIN, mini = INT_MAX;
                for ( int ch=0; ch<26; ch++ ) {
                    int diff = freq[ch];
                    if ( diff > 0 ) {
                        maxi = max ( maxi, diff );
                        mini = min ( mini, diff );
                    }
                }
                sumOfBeauty += (maxi - mini);
            }
        }
        return sumOfBeauty;
    }
};
