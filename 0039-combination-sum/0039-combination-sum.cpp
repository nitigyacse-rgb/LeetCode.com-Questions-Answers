class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void solve(int idx, vector<int>& candidates, int target) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (idx == candidates.size() || target < 0)
            return;

        // Take current candidate
        if (candidates[idx] <= target) {
            curr.push_back(candidates[idx]);
            solve(idx, candidates, target - candidates[idx]); // stay at same index
            curr.pop_back();
        }

        // Skip current candidate
        solve(idx + 1, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0, candidates, target);
        return ans;
    }
};