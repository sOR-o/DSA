#include <iostream>
#include <vector>
#include <stack>

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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* temp = st.top();
            ans.push_back(temp->val);
            st.pop();
            if (temp->right != NULL) st.push(temp->right);
            if (temp->left != NULL) st.push(temp->left);
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Test the preorderTraversal function
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = solution.preorderTraversal(root);

    // Print the result
    cout << "Result of preorderTraversal: ";
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
