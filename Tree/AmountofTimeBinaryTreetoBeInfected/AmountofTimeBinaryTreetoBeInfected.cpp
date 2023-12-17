#include <iostream>
#include <map>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    TreeNode* mapping(TreeNode* root, int start, map<TreeNode*, TreeNode*>& mpp) {
        TreeNode* result = nullptr;
        queue<TreeNode*> q;
        mpp[root] = nullptr;

        q.push(root);
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front->val == start)
                result = front;

            if (front->left) {
                mpp[front->left] = front;
                q.push(front->left);
            }
            if (front->right) {
                mpp[front->right] = front;
                q.push(front->right);
            }
        }
        return result;
    }

    void burnTree(TreeNode* root, map<TreeNode*, TreeNode*>& mpp, int& time) {
        map<TreeNode*, bool> trace;
        queue<TreeNode*> q;

        q.push(root);
        trace[root] = true;

        while (!q.empty()) {
            bool flag = false;
            int size = q.size();

            for (int i = 0; i < size; i++) {

                TreeNode* front = q.front();
                q.pop();

                if (front->left && !trace[front->left]) {
                    flag = true;
                    trace[front->left] = true;
                    q.push(front->left);
                }

                if (front->right && !trace[front->right]) {
                    flag = true;
                    trace[front->right] = true;
                    q.push(front->right);
                }

                if (mpp[front] && !trace[mpp[front]]) {
                    flag = true;
                    trace[mpp[front]] = true;
                    q.push(mpp[front]);
                }
            }
            if (flag) time++;
        }
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> mpp;
        TreeNode* target = mapping(root, start, mpp);

        int time = 0;
        burnTree(target, mpp, time);

        return time;
    }
};

int main() {
    Solution solution;

    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int startNodeValue = 2;
    int result = solution.amountOfTime(root, startNodeValue);

    cout << "Time to burn the tree from node " << startNodeValue << ": " << result << endl;

    // Don't forget to free the allocated memory for the tree nodes...

    return 0;
}
