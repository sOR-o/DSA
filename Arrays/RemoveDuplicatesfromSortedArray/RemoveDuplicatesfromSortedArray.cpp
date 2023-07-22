#include <bits/stdc++.h>
using namespace std;

// 26. Remove Duplicates from Sorted Array

// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
// The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
// Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. 
// The remaining elements of nums are not important as well as the size of nums. Return k.

// Example 1:
// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]

// Example 2:
// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        int i = 0;
        for (int j = 1; j < n; j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main() {
    // Example usage of the Solution class
    Solution solution;
    vector<int> nums(10,10);

    int length = solution.removeDuplicates(nums);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < length; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}