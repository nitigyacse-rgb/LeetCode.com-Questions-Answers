#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentPath;
        vector<bool> visited(nums.size(), false);
        
        // Step 1: Sort to bring duplicates together
        sort(nums.begin(), nums.end());
        
        backtrack(nums, visited, currentPath, result);
        return result;
    }

private:
    void backtrack(const vector<int>& nums, vector<bool>& visited, 
                   vector<int>& currentPath, vector<vector<int>>& result) {
        // Base Case: If the path length equals nums size, we found a valid permutation
        if (currentPath.size() == nums.size()) {
            result.push_back(currentPath);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // Skip if the element is already used in the current path
            if (visited[i]) continue;

            // Pruning step: Skip duplicate elements
            // If nums[i] == nums[i - 1] and nums[i - 1] was not visited, 
            // it means nums[i - 1] was already used and backtracked at this depth.
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }

            // Choose
            visited[i] = true;
            currentPath.push_back(nums[i]);

            // Explore
            backtrack(nums, visited, currentPath, result);

            // Backtrack (Un-choose)
            currentPath.pop_back();
            visited[i] = false;
        }
    }
};