#include <iostream>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void solve(TreeNode* root, int dir, int currLength, int& maxLength) {
        if (root == nullptr) return;
        maxLength = std::max(maxLength, currLength);

        solve(root->left, 0, dir ? currLength + 1 : 1, maxLength);
        solve(root->right, 1, dir ? 1 : currLength + 1, maxLength);
    }

public:
    int longestZigZag(TreeNode* root) {
        int maxLength = 0;

        solve(root, 0, 0, maxLength);
        solve(root, 1, 0, maxLength);

        return maxLength;
    }
};

int main() {
    Solution solution;

    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->left->right = new TreeNode(1);
    root->right->left->right->left = new TreeNode(1);

    int result = solution.longestZigZag(root);

    std::cout << "Length of the longest ZigZag path: " << result << std::endl;

    // Free the allocated memory for the tree nodes
    delete root->right->left->right->left;
    delete root->right->left->right;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
