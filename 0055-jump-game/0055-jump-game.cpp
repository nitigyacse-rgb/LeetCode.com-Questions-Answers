#include <vector>
#include <algorithm>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int farthest = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            // If the current index is beyond the farthest reachable index, we're stuck
            if (i > farthest) {
                return false;
            }

            // Update the maximum distance we can reach
            farthest = std::max(farthest, i + nums[i]);

            // Early exit if we can already reach or pass the last index
            if (farthest >= n - 1) {
                return true;
            }
        }

        return true;
    }
};