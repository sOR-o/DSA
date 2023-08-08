#include <bits/stdc++.h>
using namespace std;

// 164. Maximum Gap

// Given an integer array nums, return the maximum difference between two successive elements in its sorted form. 
// If the array contains less than two elements, return 0.
// You must write an algorithm that runs in linear time and uses linear extra space.

// Input: nums = [3,6,9,1]
// Output: 3

// Input: nums = [10]
// Output: 0


class Solution {
public:
    int maximumGap(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int maxi = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            maxi = std::max(maxi, nums[i + 1] - nums[i]);
        }

        return maxi;
    }
};

int main() {
    Solution solution;
    vector<int> nums;

    // Using push_back to populate the vector
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(9);
    nums.push_back(1);
    
    int maxGap = solution.maximumGap(nums);
    cout << "Maximum Gap is: " << maxGap << endl;

    return 0;
}