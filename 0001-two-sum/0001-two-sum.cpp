#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Map to store: Key = number, Value = its index
        std::unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Check if the complement already exists in the map
            if (numMap.find(complement) != numMap.end()) {
                // If found, return the indices of the complement and current element
                return {numMap[complement], i};
            }
            
            // Otherwise, insert the current number and its index into the map
            numMap[nums[i]] = i;
        }
        
        // Return an empty vector if no solution is found (though constraints guarantee one exists)
        return {};
    }
};