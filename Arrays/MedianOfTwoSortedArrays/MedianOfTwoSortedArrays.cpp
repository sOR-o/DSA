#include <bits/stdc++.h>
using namespace std;

//4. Median of Two Sorted Arrays



// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

// Example 1:
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000

// Example 2:
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000

class Solution {
public:
    /**
     * Finds the median of two sorted arrays.
     *
     * @param nums1    The first sorted array of integers.
     * @param nums2    The second sorted array of integers.
     * @return         The median value as a double.
     */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int m = nums1.size();
        int n = nums2.size();
        int i = 0, j = 0;

        while (i < m && j < n) {
            if (nums1[i] > nums2[j])
                ans.push_back(nums2[j++]);
            else if (nums1[i] < nums2[j])
                ans.push_back(nums1[i++]);
            else {
                ans.push_back(nums1[i]);
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        while (i < m)
            ans.push_back(nums1[i++]);
        while (j < n)
            ans.push_back(nums2[j++]);

        if (ans.size() % 2 == 0)
            return (ans[ans.size() / 2 - 1] + ans[ans.size() / 2]) / 2.0;
        else
            return ans[ans.size() / 2.0];
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Example usage
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    vector<int> nums2;
    nums2.push_back(2);
    double median = solution.findMedianSortedArrays(nums1, nums2);

    // Print the median
    cout << "Median of the two sorted arrays: " << median << endl;

    return 0;
}