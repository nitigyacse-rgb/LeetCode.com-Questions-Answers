#include <string>
#include <vector>

class Solution {
public:
    std::string getPermutation(int n, int k) {
        std::vector<int> numbers;
        std::vector<int> fact(n, 1);
        
        // Compute factorials and initialize available numbers list
        for (int i = 1; i < n; ++i) {
            fact[i] = fact[i - 1] * i;
        }
        for (int i = 1; i <= n; ++i) {
            numbers.push_back(i);
        }

        // Convert k to 0-based index
        k--;

        std::string result = "";
        
        for (int i = n; i >= 1; --i) {
            int block_size = fact[i - 1];
            int idx = k / block_size;
            
            result += std::to_string(numbers[idx]);
            numbers.erase(numbers.begin() + idx); // Remove used number
            
            k %= block_size;
        }

        return result;
    }
};