#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    // ... (rest of your code)

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // ... (rest of your code)
    }
};

int main() {
    Solution solution;

    // Test the maximalRectangle function
    vector<vector<char> > matrix = {  // Add space or use 'vector<vector<char> >'
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    int result = solution.maximalRectangle(matrix);

    // Print the result
    cout << "Result of maximalRectangle: " << result << endl;

    return 0;
}
