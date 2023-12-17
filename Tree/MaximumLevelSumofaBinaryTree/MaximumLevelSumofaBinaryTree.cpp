#include <iostream>
#include <climits>
#include <queue>

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
public:
    int maxLevelSum(TreeNode* root) {
        int maxiSum = INT_MIN;
        int levelCount = 0, level = 0;

        if (root == nullptr)
            return level;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int sum = 0;
            levelCount++;

            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);

                sum += (front->val);
            }
            if (sum > maxiSum) {
                level = levelCount;
                maxiSum = sum;
            }
        }
        return level;
    }
};

int main() {
    Solution solution;

    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    int result = solution.maxLevelSum(root);

    std::cout << "Level with maximum sum: " << result << std::endl;

    // Free the allocated memory for the tree nodes
    delete root->left->left;
    delete root->left->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
