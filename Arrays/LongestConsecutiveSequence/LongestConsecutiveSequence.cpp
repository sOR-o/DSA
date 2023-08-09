#include <bits/stdc++.h>
using namespace std;

// 128. Longest Consecutive Sequence

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.

// Input: nums = [100,4,200,1,3,2]
// Output: 4

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int maxi = 1;
        int n = nums.size();
        if(n == 0) return 0;
        unordered_set<int> s;

        for(int i = 0; i < n; i++) s.insert(nums[i]);
        
        for(int it : s){
            if(s.find(it-1) == s.end()){
                int count = 1;
                int x = it;

                while(s.find(x+1) != s.end()){
                    x++;
                    count++;
                }
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};

int main() {
    Solution solution;

    // Using push_back to populate the nums vector
    vector<int> nums;
    nums.push_back(100);
    nums.push_back(4);
    nums.push_back(200);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);

    int longestConsecutiveLength = solution.longestConsecutive(nums);

    cout << "Longest Consecutive Length: " << longestConsecutiveLength << endl;

    return 0;
}