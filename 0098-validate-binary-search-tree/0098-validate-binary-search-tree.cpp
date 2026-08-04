#include <climits>
#include <algorithm>

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
    bool validate(TreeNode* node, long long low, long long high) {
        if (!node) {
            return true;
        }

        // Current node's value must be strictly within bounds
        if (node->val <= low || node->val >= high) {
            return false;
        }

        // Left child must be strictly less than node->val
        // Right child must be strictly greater than node->val
        return validate(node->left, low, node->val) && 
               validate(node->right, node->val, high);
    }

public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
};