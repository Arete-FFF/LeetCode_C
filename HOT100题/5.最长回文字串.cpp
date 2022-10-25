#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i=0; i<n; i++) {
            dp[i][i] = true;
            if (i+1<n) {
                dp[i][i+1] = s[i]==s[i+1];
            }
        }



        int begin=0, end=0;

        for (int len=2; len<n; len++) {
            for (int i=0; len+i<n; i++) {
                int j=i+len;
                dp[i][j] = (s[i]==s[j]) && dp[i+1][j-1];

                if (dp[i][j]  && j-i > end-begin) {
                    begin = i;
                    end = j;
                }
            }
        }
        return string(s.begin()+begin, s.begin()+end+1);
    }
};

int main()
{
    Solution t;
    string s = "dbbbd";
    cout << t.longestPalindrome(s) << endl;
}
