#include <bits/stdc++.h>
using namespace std;

// 53. Maximum Subarray

// Given an integer array nums, find the subarray with the largest sum, and return its sum.

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
       
        int maxi = INT_MIN, Sum = 0;
        for (int i = 0; i < n; i++) {
            Sum += nums[i]; 
            maxi = max(maxi, Sum);
            Sum = max(Sum, 0);
        } 
        return maxi;
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    
    // Adding elements using push_back
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);
    
    int maxSum = solution.maxSubArray(nums);
    cout << "Maximum subarray sum: " << maxSum << endl;
    
    return 0;
}





