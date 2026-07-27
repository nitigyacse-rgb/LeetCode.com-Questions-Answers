#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }

        int k = 2; // Pointer for placing valid elements

        for (int i = 2; i < n; ++i) {
            // Compare current element with the element 2 positions back in the valid region
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};