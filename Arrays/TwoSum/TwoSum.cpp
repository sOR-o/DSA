#include <bits/stdc++.h>
using namespace std;

// Leetcode 1. Two Sum


// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]

// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]

class Solution {
public:
    /**
     * Finds the indices of two numbers in the input vector that add up to the target.
     *
     * @param nums    The vector of integers.
     * @param target  The target integer.
     * @return        A vector of two integers representing the indices of the numbers that add up to the target.
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int flag = 0;
        for(int i = 0; i < nums.size()-1; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                break;
            }
        }
        return ans;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Example usage
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);

    // Print the result
    cout << "Indices of the two numbers that add up to the target: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}