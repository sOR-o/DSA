#include <bits/stdc++.h>
using namespace std;

// 152. Maximum Product Subarray

// Given an integer array nums, find a subarray
// that has the largest product, and return the product.
// The test cases are generated so that the answer will fit in a 32-bit integer.

// Input: nums = [2,3,-2,4]
// Output: 6

// Input: nums = [-2,0,-1]
// Output: 0


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1, suffix = 1;
        int maxi = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (prefix == 0)
                prefix = 1;
            if (suffix == 0)
                suffix = 1;

            prefix *= nums[i];
            suffix *= nums[nums.size() - i - 1];
            maxi = max(maxi, max(prefix, suffix));
        }
        return maxi;
    }
};

int main() {
    Solution solution;

    // Using push_back to populate the nums vector
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(-2);
    nums.push_back(4);

    int maxProductValue = solution.maxProduct(nums);

    cout << "Maximum product: " << maxProductValue << endl;

    return 0;
}