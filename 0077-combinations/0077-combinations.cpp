#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }

private:
    void backtrack(int start, int n, int k, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Pruning: stop if remaining candidates are fewer than needed
        int needed = k - current.size();
        for (int i = start; i <= n - needed + 1; ++i) {
            current.push_back(i);
            backtrack(i + 1, n, k, current, result);
            current.pop_back(); // Backtrack
        }
    }
};