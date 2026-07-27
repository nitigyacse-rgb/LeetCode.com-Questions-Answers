#include <string>
#include <unordered_map>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        std::unordered_map<char, int> target_counts;
        for (char c : t) {
            target_counts[c]++;
        }

        int required_count = t.length();
        int left = 0, right = 0;
        int min_len = INT_MAX;
        int start_idx = 0;

        while (right < s.length()) {
            char right_char = s[right];
            
            // If the character is in 't' and we still need more of it
            if (target_counts.find(right_char) != target_counts.end()) {
                if (target_counts[right_char] > 0) {
                    required_count--;
                }
                target_counts[right_char]--;
            }

            // Shrink window from the left while it remains valid
            while (required_count == 0) {
                int current_window_len = right - left + 1;
                if (current_window_len < min_len) {
                    min_len = current_window_len;
                    start_idx = left;
                }

                char left_char = s[left];
                if (target_counts.find(left_char) != target_counts.end()) {
                    target_counts[left_char]++;
                    // If count becomes positive, we lost a required character
                    if (target_counts[left_char] > 0) {
                        required_count++;
                    }
                }
                left++;
            }

            right++;
        }

        return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};