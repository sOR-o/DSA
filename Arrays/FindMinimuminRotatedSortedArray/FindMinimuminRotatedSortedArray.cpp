#include <bits/stdc++.h>
using namespace std;

// 153. Find Minimum in Rotated Sorted Array

// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
// Given the sorted rotated array nums of unique elements, return the minimum element of this array.
// You must write an algorithm that runs in O(log n) time.

// Input: nums = [3,4,5,1,2]
// Output: 1

// Input: nums = [11,13,15,17]
// Output: 11

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end - start) / 2;

        if (nums[start] < nums[end])
            return nums[start];

        while (start < end) {
            if (nums[mid] >= nums[0])
                start = mid + 1;
            else if (nums[mid] <= nums[0])
                end = mid;
            else if (nums[mid] < nums[mid + 1] && nums[mid] < nums[mid - 1])
                return nums[mid];
            mid = start + (end - start) / 2;
        }
        return nums[start];
    }
};

int main() {
    Solution solution;

    // Using push_back to populate the nums vector
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);

    int minValue = solution.findMin(nums);

    cout << "Minimum value: " << minValue << endl;

    return 0;
}