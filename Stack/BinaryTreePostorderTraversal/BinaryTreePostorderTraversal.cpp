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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL){
            return res;
        }
        stack<TreeNode *> s1,s2;
        s1.push(root);
        while(!s1.empty()){
            root=s1.top();
            s1.pop();
            s2.push(root);
            if(root->left!=NULL){
                s1.push(root->left);
            }
            if(root->right!=NULL){
                s1.push(root->right);
            }
        }
        while(!s2.empty()){
            res.push_back(s2.top()->val);
            s2.pop();
        }
        return res;
    }
};

int main() {
    Solution solution;

    // Test the postorderTraversal function
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = solution.postorderTraversal(root);

    // Print the result
    cout << "Result of postorderTraversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the memory (optional)
    // Note: Since the tree nodes are dynamically allocated, it's a good practice to free the memory.
    // This is not necessary for the testing purpose, but it's good to include in a complete program.
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
