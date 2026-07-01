class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Vector to store the last seen index of each character
        // Initialized to -1 to signify the character hasn't been seen yet
        vector<int> lastSeen(256, -1);
        
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];
            
            // If the character was seen inside the current window, 
            // move the left pointer right past its previous occurrence
            if (lastSeen[currentChar] >= left) {
                left = lastSeen[currentChar] + 1;
            }
            
            // Record/update the current character's index
            lastSeen[currentChar] = right;
            
            // Update maximum length found so far
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};