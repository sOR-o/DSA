#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root->val == 0)
            return false;
        if (root->val == 1)
            return true;

        if (root->val == 2) {
            return evaluateTree(root->left) || evaluateTree(root->right);
        }

        if (root->val == 3) {
            return evaluateTree(root->left) && evaluateTree(root->right);
        }

        return true;
    }
};

int main() {
    Solution solution;

    // Example usage:
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(0);

    bool result = solution.evaluateTree(root);

    std::cout << "Result of evaluating the tree: " << std::boolalpha << result << std::endl;

    // Free the allocated memory for the tree nodes
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
