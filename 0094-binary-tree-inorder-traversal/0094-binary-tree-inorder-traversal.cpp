#include <vector>

class Solution {
private:
    void traverse(TreeNode* node, std::vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        traverse(node->left, result);  // Visit Left
        result.push_back(node->val);   // Visit Root
        traverse(node->right, result); // Visit Right
    }

public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        traverse(root, result);
        return result;
    }
};