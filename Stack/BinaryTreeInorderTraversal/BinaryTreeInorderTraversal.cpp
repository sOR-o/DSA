#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void inorder(TreeNode* root, vector<int> &ans) {
        if (root != NULL) {
            inorder(root->left, ans);
            ans.push_back(root->val);
            inorder(root->right, ans);
        }
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

int main() {
    Solution solution;

    // Test the inorderTraversal function
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = solution.inorderTraversal(root);

    // Print the result
    cout << "Result of inorderTraversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the memory (optional)
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
