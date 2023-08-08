#include <bits/stdc++.h>
using namespace std;

// 169. Majority Element

// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.

// Input: nums = [3,2,3]
// Output: 3

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int count = 0;
        int element;

        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                element = nums[i];
                count = 1;
            }
            else if (nums[i] == element){
                count++;
            }
            else count--;
        }

        count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == element) count++;
        }

        if(count > nums.size() / 2) return element;
        return -1;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums;

    // Using push_back to populate the vector
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(2);

    int majority = solution.majorityElement(nums);
    if (majority != -1) {
        std::cout << "Majority element is: " << majority << std::endl;
    } else {
        std::cout << "No majority element found." << std::endl;
    }

    return 0;
}





