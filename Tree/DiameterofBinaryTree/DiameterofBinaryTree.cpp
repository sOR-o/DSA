#include <bits/stdc++.h>
using namespace std;

// 543. Diameter of Binary Tree

// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
// This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.

// Example 1:
// Input: root = [1,2,3,4,5]
// Output: 3

// Example 2:
// Input: root = [1,2]
// Output: 1

// Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    /**
     * Recursive function to find the height and diameter of a binary tree.
     * The height is the number of nodes along the longest path from the root
     * node down to the farthest leaf node.
     * The diameter is the length of the longest path between any two nodes in the tree.
     *
     * @param root Pointer to the root node of the binary tree.
     * @return A pair containing the height and diameter of the binary tree.
     */
    std::pair<int, int> solve(TreeNode* root) {
        if (root == nullptr) {
            return std::make_pair(0, 0);
        }

        std::pair<int, int> left = solve(root->left);
        std::pair<int, int> right = solve(root->right);

        int height = 1 + std::max(left.first, right.first);
        int diameter = std::max(left.second, max(right.second, left.first + right.first));

        return std::make_pair(height, diameter);
    }

public:
    /**
     * Calculates the diameter of a binary tree.
     * The diameter is defined as the length of the longest path between any two nodes in the tree.
     *
     * @param root Pointer to the root node of the binary tree.
     * @return The diameter of the binary tree.
     */
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return solve(root).second;
    }
};

int main() {
    // Create a binary tree for demonstration purposes
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);

    Solution solution;
    int diameter = solution.diameterOfBinaryTree(root);

    std::cout << "Diameter of the binary tree: " << diameter << std::endl;

    // Clean up the memory allocated for the binary tree
    // (You may want to use a proper tree traversal for more complex trees)
    delete root->left->left;
    delete root->left->right->left;
    delete root->left->right->right;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}