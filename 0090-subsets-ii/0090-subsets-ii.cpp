#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        
        backtrack(0, nums, path, result);
        return result;
    }

private:
    void backtrack(int start, const std::vector<int>& nums, std::vector<int>& path, std::vector<std::vector<int>>& result) {
        result.push_back(path);
        
        for (int i = start; i < nums.size(); ++i) {
            // Skip duplicates
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            backtrack(i + 1, nums, path, result);
            path.pop_back();
        }
    }
};