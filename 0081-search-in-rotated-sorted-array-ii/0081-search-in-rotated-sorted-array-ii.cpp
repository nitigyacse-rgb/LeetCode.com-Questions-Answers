class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // Case 1: When low, mid, and high are equal, we can't determine 
            // which half is sorted. Shrink the search space.
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }
            // Case 2: Left half is sorted
            else if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1; // Target lies in the left half
                } else {
                    low = mid + 1;  // Target lies in the right half
                }
            }
            // Case 3: Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;  // Target lies in the right half
                } else {
                    high = mid - 1; // Target lies in the left half
                }
            }
        }

        return false;
    }
};