#include <bits/stdc++.h>
using namespace std;

// 48. Rotate Image

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
// DO NOT allocate another 2D matrix and do the rotation.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

// Example 2:
// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();

        // Transpose the matrix
        for (int i = 0; i < row; i++) {
            for (int j = i; j < column; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row of the transposed matrix
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column / 2; j++) {
                swap(matrix[i][j], matrix[i][column - 1 - j]);
            }
        }
    }
};

void printMatrix(const vector<vector<int>>& matrix) {
    int row = matrix.size();
    int column = matrix[0].size();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;

    // Test case 1
    vector<vector<int>> matrix1(3, vector<int>(3));
    matrix1[0][0] = 1;
    matrix1[0][1] = 2;
    matrix1[0][2] = 3;
    matrix1[1][0] = 4;
    matrix1[1][1] = 5;
    matrix1[1][2] = 6;
    matrix1[2][0] = 7;
    matrix1[2][1] = 8;
    matrix1[2][2] = 9;

    cout << "Original Matrix 1:\n";
    printMatrix(matrix1);
    solution.rotate(matrix1);
    cout << "Rotated Matrix 1:\n";
    printMatrix(matrix1);
    cout << endl;

    // Test case 2
    vector<vector<int>> matrix2(4, vector<int>(4));
    matrix2[0][0] = 5;
    matrix2[0][1] = 1;
    matrix2[0][2] = 9;
    matrix2[0][3] = 11;
    matrix2[1][0] = 2;
    matrix2[1][1] = 4;
    matrix2[1][2] = 8;
    matrix2[1][3] = 10;
    matrix2[2][0] = 13;
    matrix2[2][1] = 3;
    matrix2[2][2] = 6;
    matrix2[2][3] = 7;
    matrix2[3][0] = 15;
    matrix2[3][1] = 14;
    matrix2[3][2] = 12;
    matrix2[3][3] = 16;

    cout << "Original Matrix 2:\n";
    printMatrix(matrix2);
    solution.rotate(matrix2);
    cout << "Rotated Matrix 2:\n";
    printMatrix(matrix2);
    cout << endl;

    return 0;
}