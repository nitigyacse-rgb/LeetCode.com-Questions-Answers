#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    std::vector<TreeNode*> buildTrees(int start, int end) {
        std::vector<TreeNode*> result;
        
        // Base case: range is empty, return vector containing nullptr
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }

        // Try each value in [start, end] as the root
        for (int i = start; i <= end; ++i) {
            // Generate all left and right subtrees
            std::vector<TreeNode*> leftSubtrees = buildTrees(start, i - 1);
            std::vector<TreeNode*> rightSubtrees = buildTrees(i + 1, end);

            // Connect root 'i' to all combinations of left and right subtrees
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }

        return result;
    }

public:
    std::vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }
};