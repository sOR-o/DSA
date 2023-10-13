#include <bits/stdc++.h>
using namespace std;

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
    

public:
    TreeNode* invertBinaryTree(TreeNode* root)
    {
        if(!root) return root;
        swap(root->left,root->right);
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
        return root;
    }
    void levelOrder(TreeNode* root)
    {
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode * cur=q.front();
            q.pop();
            cout<<cur->val<<" ";
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
    }
};

int main() {
    // Create a binary tree for demonstration purposes
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left= new TreeNode(6);
    root->right->right=new TreeNode(7);


    Solution solution;
    solution.levelOrder(root);
    solution.invertBinaryTree(root);
    cout<<endl<<"After inverting"<<endl;
    solution.levelOrder(root);

    

    // Clean up the memory allocated for the binary tree
    // (You may want to use a proper tree traversal for more complex trees)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}