#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }

private:
    void backtrack(int start_idx, const std::vector<int>& nums, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Every state reached represents a valid subset
        result.push_back(current);

        for (int i = start_idx; i < nums.size(); ++i) {
            current.push_back(nums[i]);
            backtrack(i + 1, nums, current, result);
            current.pop_back(); // Backtrack
        }
    }
};