#include <bits/stdc++.h>
using namespace std;

// 136. Single Number

// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.

// Input: nums = [2,2,1]
// Output: 1

// Input: nums = [4,1,2,1,2]
// Output: 4

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (int i = 0; i < nums.size(); i++) {
            x = x ^ nums[i];
        }
        return x;
    }
};

int main() {
    Solution solution;

    // Using push_back to populate the nums vector
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);

    int singleNumberValue = solution.singleNumber(nums);

    cout << "Single Number: " << singleNumberValue << endl;

    return 0;
}