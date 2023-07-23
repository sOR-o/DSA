#include <bits/stdc++.h>
using namespace std;

// 33. Search in Rotated Sorted Array

// There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that 
// the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
// For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, 
// or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end - start) / 2;

        while (start <= end) {
            if (target == nums[mid])
                return mid;

            if (nums[mid] >= nums[start]) {
                if (target >= nums[start] && target <= nums[mid])
                    end = mid;
                else
                    start = mid + 1;
            } else {
                if (target <= nums[end] && target >= nums[mid])
                    start = mid;
                else
                    end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }

        return -1;
    }
};

int main() {
    using namespace std; // Add this line to use the std namespace.

    Solution solution;
    vector<int> nums;
    int n;

    cout << "Enter the number of elements in nums: ";
    cin >> n;

    cout << "Enter the elements of nums one by one:\n";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    int target;
    cout << "Enter the target value to search: ";
    cin >> target;

    int result = solution.search(nums, target);
    if (result != -1)
        cout << "Target found at index: " << result << endl;
    else
        cout << "Target not found in nums.\n";

    return 0;
}