#include <bits/stdc++.h>
using namespace std;

// 27. Remove Element

// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. 
// Then return the number of elements in nums which are not equal to val.

// Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

// Change the array nums such that the first k elements of nums contain the elements which are not equal to val. 
// The remaining elements of nums are not important as well as the size of nums.
// Return k.

// Example 1:
// Input: nums = [3,2,2,3], val = 3
// Output: 2, nums = [2,2,_,_]

// Example 2:
// Input: nums = [0,1,2,2,3,0,4,2], val = 2
// Output: 5, nums = [0,1,4,0,3,_,_,_]

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == val) {
                ans++;
            } else {
                nums[i - ans] = nums[i];
            }
        }
        return n - ans;
    }
};

int main() {
    // Example usage of the Solution class
    Solution solution;
    vector<int> nums;
    int val = 3;

    // Initializing nums vector one by one
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(4);

    int length = solution.removeElement(nums, val);

    cout << "Array after removing " << val << ": ";
    for (int i = 0; i < length; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}