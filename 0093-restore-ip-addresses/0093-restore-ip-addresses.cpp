#include <iostream>
#include <vector>
#include <string>

class Solution {
private:
    void backtrack(const std::string& s, int index, int dots, std::string current, std::vector<std::string>& result) {
        // Base Case: If 4 segments are formed and we consumed the entire string
        if (dots == 4) {
            if (index == s.length()) {
                current.pop_back(); // Remove the trailing dot
                result.push_back(current);
            }
            return;
        }

        // Try placing a dot after 1, 2, or 3 digits
        for (int len = 1; len <= 3; ++len) {
            if (index + len > s.length()) break;

            std::string segment = s.substr(index, len);

            // Validation checks
            // 1. Leading zero check (e.g., "01" or "00" is invalid)
            if (segment.length() > 1 && segment[0] == '0') break;

            // 2. Value range check (0 <= value <= 255)
            int val = std::stoi(segment);
            if (val > 255) break;

            // Recurse for the next segment
            backtrack(s, index + len, dots + 1, current + segment + ".", result);
        }
    }

public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> result;
        
        // Quick Pruning: An IPv4 string must have length between 4 and 12
        if (s.length() < 4 || s.length() > 12) {
            return result;
        }

        backtrack(s, 0, 0, "", result);
        return result;
    }
};