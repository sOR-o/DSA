#include <bits/stdc++.h>
using namespace std;

// 48. Rotate Image

// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// Example 2:
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int top = 0;
        int left = 0;
        int right = n - 1;
        int bottom = m - 1;

        vector<int> ans;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++)
                ans.push_back(mat[top][i]);

            top++;

            for (int i = top; i <= bottom; i++)
                ans.push_back(mat[i][right]);

            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    ans.push_back(mat[bottom][i]);
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(mat[i][left]);
                left++;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<vector<int>> mat1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> result1 = solution.spiralOrder(mat1);
    cout << "Spiral Order 1: ";
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;

    // Test case 2
    vector<vector<int>> mat2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    vector<int> result2 = solution.spiralOrder(mat2);
    cout << "Spiral Order 2: ";
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}