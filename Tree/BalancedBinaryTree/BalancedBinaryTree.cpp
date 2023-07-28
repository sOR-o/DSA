#include <bits/stdc++.h>
using namespace std;

// 110. Balanced Binary Tree

// Given a binary tree, determine if it is height-balanced.

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: true

// Example 2:
// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false

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
     * Calculates the maximum depth of a binary tree.
     * The maximum depth is defined as the number of nodes along the longest path 
     * from the root node down to the farthest leaf node.
     *
     * @param root Pointer to the root node of the binary tree.
     * @return The maximum depth of the binary tree.
     */
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        return std::max(leftHeight, rightHeight) + 1;
    }

public:
    /**
     * Determines whether a binary tree is balanced or not.
     * A binary tree is considered balanced if the heights of the two subtrees of
     * every node never differ by more than one.
     *
     * @param root Pointer to the root node of the binary tree.
     * @return True if the binary tree is balanced, False otherwise.
     */
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        bool difference = std::abs(maxDepth(root->left) - maxDepth(root->right)) <= 1;

        if (left && right && difference) {
            return true;
        }

        return false;
    }
};

int main() {
    // Create a binary tree for demonstration purposes
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    bool isBalanced = solution.isBalanced(root);

    if (isBalanced) {
        std::cout << "The binary tree is balanced." << std::endl;
    } else {
        std::cout << "The binary tree is not balanced." << std::endl;
    }

    // Clean up the memory allocated for the binary tree
    // (You may want to use a proper tree traversal for more complex trees)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}