#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
    // memo[i][j][len]: 
    // -1 = unvisited, 0 = false, 1 = true
    int memo[31][31][32];

    bool helper(const string& s1, const string& s2, int i, int j, int len) {
        if (memo[i][j][len] != -1) {
            return memo[i][j][len];
        }

        // Base Case 1: Substrings are identical
        if (s1.compare(i, len, s2, j, len) == 0) {
            return memo[i][j][len] = 1;
        }

        // Pruning: Check character frequencies using a fixed 26-element array
        int count[26] = {0};
        for (int k = 0; k < len; ++k) {
            count[s1[i + k] - 'a']++;
            count[s2[j + k] - 'a']--;
        }
        for (int c = 0; c < 26; ++c) {
            if (count[c] != 0) {
                return memo[i][j][len] = 0;
            }
        }

        // Try every possible split position k (1 <= k < len)
        for (int k = 1; k < len; ++k) {
            // Case 1: Without Swap
            // Left matches Left (s1[i..i+k] vs s2[j..j+k]) 
            // AND Right matches Right (s1[i+k..i+len] vs s2[j+k..j+len])
            if (helper(s1, s2, i, j, k) && helper(s1, s2, i + k, j + k, len - k)) {
                return memo[i][j][len] = 1;
            }

            // Case 2: With Swap
            // Left matches Right (s1[i..i+k] vs s2[j+len-k..j+len]) 
            // AND Right matches Left (s1[i+k..i+len] vs s2[j..j+len-k])
            if (helper(s1, s2, i, j + len - k, k) && helper(s1, s2, i + k, j, len - k)) {
                return memo[i][j][len] = 1;
            }
        }

        return memo[i][j][len] = 0;
    }

public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        // Initialize memo table with -1
        for (int i = 0; i < 31; ++i) {
            for (int j = 0; j < 31; ++j) {
                for (int l = 0; l < 32; ++l) {
                    memo[i][j][l] = -1;
                }
            }
        }
        return helper(s1, s2, 0, 0, n);
    }
};