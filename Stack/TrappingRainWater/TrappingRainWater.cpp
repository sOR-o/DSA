#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size()-1;
        int leftMax = 0, rightMax = 0;

        while(left <= right) {
            if(height[left] <= height[right]) {
                if(height[left] >= leftMax) leftMax = height[left];
                else ans += leftMax - height[left];

                left++;
            }
            else {
                if(height[right] >= rightMax) rightMax = height[right];
                else ans += rightMax - height[right];

                right--;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Test the trap function with different inputs
    vector<int> heights1;
    heights1.push_back(0);
    heights1.push_back(1);
    heights1.push_back(0);
    heights1.push_back(2);
    heights1.push_back(1);
    heights1.push_back(0);
    heights1.push_back(1);
    heights1.push_back(3);
    heights1.push_back(2);
    heights1.push_back(1);
    heights1.push_back(2);
    heights1.push_back(1);

    int result1 = solution.trap(heights1);
    cout << "Result of trap: " << result1 << endl;

    vector<int> heights2;
    heights2.push_back(4);
    heights2.push_back(2);
    heights2.push_back(0);
    heights2.push_back(3);
    heights2.push_back(2);
    heights2.push_back(5);

    int result2 = solution.trap(heights2);
    cout << "Result of trap: " << result2 << endl;

    // Add more test cases as needed...

    return 0;
}