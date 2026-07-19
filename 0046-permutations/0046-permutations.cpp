class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);      // Choose
            backtrack(nums, idx + 1);      // Explore
            swap(nums[idx], nums[i]);      // Undo (Backtrack)
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};