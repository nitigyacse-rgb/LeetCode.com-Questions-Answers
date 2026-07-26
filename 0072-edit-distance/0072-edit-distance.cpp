#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.length();
        int n = word2.length();
        
        // dp[j] stores the edit distance for word1[0...i-1] and word2[0...j-1]
        std::vector<int> dp(n + 1, 0);
        
        // Base case: converting empty word1 to word2[0...j-1] requires j insertions
        for (int j = 0; j <= n; ++j) {
            dp[j] = j;
        }
        
        for (int i = 1; i <= m; ++i) {
            int prev = dp[0]; // Stores dp[i-1][j-1] before it gets overwritten
            dp[0] = i;        // Base case: converting word1[0...i-1] to empty word2
            
            for (int j = 1; j <= n; ++j) {
                int temp = dp[j];
                
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = prev;
                } else {
                    dp[j] = 1 + std::min({dp[j],      // Deletion
                                          dp[j - 1],  // Insertion
                                          prev});     // Replacement
                }
                
                prev = temp;
            }
        }
        
        return dp[n];
    }
};