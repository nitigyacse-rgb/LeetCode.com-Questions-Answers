class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        int totalLeft = (m + n + 1) / 2;
        
        while (low <= high) {
            int i = low + (high - low) / 2; // Partition index for nums1
            int j = totalLeft - i;          // Partition index for nums2
            
            // Boundary values (handle edge cases where partition is at the ends)
            int A_left = (i == 0) ? INT_MIN : nums1[i - 1];
            int A_right = (i == m) ? INT_MAX : nums1[i];
            
            int B_left = (j == 0) ? INT_MIN : nums2[j - 1];
            int B_right = (j == n) ? INT_MAX : nums2[j];
            
            // Check if we found the correct partition
            if (A_left <= B_right && B_left <= A_right) {
                // If total number of elements is odd
                if ((m + n) % 2 != 0) {
                    return max(A_left, B_left);
                }
                // If total number of elements is even
                return (max(A_left, B_left) + min(A_right, B_right)) / 2.0;
            }
            else if (A_left > B_right) {
                // We took too many elements from nums1, move left
                high = i - 1;
            }
            else {
                // We took too few elements from nums1, move right
                low = i + 1;
            }
        }
        
        return 0.0;
    }
};