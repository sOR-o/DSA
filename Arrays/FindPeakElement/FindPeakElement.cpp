#include <bits/stdc++.h>
using namespace std;

// 162. Find Peak Element

// A peak element is an element that is strictly greater than its neighbors.
// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, 
// return the index to any of the peaks.
// You may imagine that nums[-1] = nums[n] = -∞. In other words, 
// an element is always considered to be strictly greater than a neighbor that is outside the array.
// You must write an algorithm that runs in O(log n) time

// Input: nums = [1,2,3,1]
// Output: 2

// Input: nums = [1,2,1,3,5,6,4]
// Output: 5

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end - start) / 2;

        while (start < end) {
            if (nums[mid] > nums[mid + 1])
                end = mid;
            else
                start = mid + 1;

            mid = start + (end - start) / 2;
        }
        return start;
    }
};

int main() {
    Solution solution;

    // Using push_back to populate the nums vector
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);

    int peakIndex = solution.findPeakElement(nums);

    cout << "Peak element index: " << peakIndex << endl;

    return 0;
}




