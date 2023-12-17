#include <iostream>
#include <vector>
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
    void solve(TreeNode* root, std::vector<int>& track, int& count) {
        if (root == nullptr) return;
        track.push_back(root->val);

        auto maxElement = std::max_element(track.begin(), track.end());
        if (root->val >= *maxElement) count++;

        solve(root->left, track, count);
        solve(root->right, track, count);

        track.pop_back();
    }

public:
    int goodNodes(TreeNode* root) {
        std::vector<int> track;
        int count = 0;
        solve(root, track, count);
        return count;
    }
};

int main() {
    Solution solution;

    // Example usage:
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(1);

    int result = solution.goodNodes(root);

    std::cout << "Number of good nodes in the tree: " << result << std::endl;

    // Free the allocated memory for the tree nodes
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
