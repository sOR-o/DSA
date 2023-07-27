#include <bits/stdc++.h>
using namespace std;

// 59. Spiral Matrix II

// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

// Example 1:
// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]

// Example 2:
// Input: n = 1
// Output: [[1]]

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        int top = 0;
        int left = 0;
        int right = n - 1;
        int bottom = n - 1;
        int num = 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++)
                ans[top][i] = num++;

            top++;

            for (int i = top; i <= bottom; i++)
                ans[i][right] = num++;

            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    ans[bottom][i] = num++;
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans[i][left] = num++;
                left++;
            }
        }

        return ans;
    }
};

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<int>> result = solution.generateMatrix(n);
    cout << "Generated Matrix:\n";
    printMatrix(result);

    return 0;
}