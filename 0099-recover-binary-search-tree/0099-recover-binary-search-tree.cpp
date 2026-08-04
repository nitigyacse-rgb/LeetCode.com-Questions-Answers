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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // Find inverted pairs
        if (prev && prev->val > root->val) {
            // First time we see an inversion, set 'first' to prev
            if (!first) {
                first = prev;
            }
            // Always update 'second' to current node for both 1st and 2nd inversions
            second = root;
        }

        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        
        // Swap values back
        if (first && second) {
            std::swap(first->val, second->val);
        }
    }
};