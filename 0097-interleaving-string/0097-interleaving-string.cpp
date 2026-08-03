#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        
        if (m + n != s3.length()) {
            return false;
        }

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        // Base case: matching s1 only
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }

        // Base case: matching s2 only
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                bool choose_s1 = dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
                bool choose_s2 = dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
                dp[i][j] = choose_s1 || choose_s2;
            }
        }

        return dp[m][n];
    }
};