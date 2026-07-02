#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLength = 1;
        
        // Helper lambda function to expand around a given center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                int currentLength = right - left + 1;
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                    start = left;
                }
                left--;
                right++;
            }
        };
        
        for (int i = 0; i < s.length(); i++) {
            expandAroundCenter(i, i);       // Odd length palindromes (e.g., "aba")
            expandAroundCenter(i, i + 1);   // Even length palindromes (e.g., "bba")
        }
        
        return s.substr(start, maxLength);
    }
};