#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        for(int i = 0; i < nums1.size(); i++) {
            int found = 0;  
            int temp = -1; 

            for(int j = 0; j < nums2.size(); j++) {
                if(found && nums2[j] > nums1[i]) {
                    temp = nums2[j];
                    break;
                }
                if(nums2[j] == nums1[i]) found = 1;  
            }
            nums1[i] = temp;
        }
        return nums1;
    }
};

int main() {
    Solution solution;

    // Test the nextGreaterElement function
    vector<int> nums1;
    nums1.push_back(4);
    nums1.push_back(1);
    nums1.push_back(2);

    vector<int> nums2;
    nums2.push_back(1);
    nums2.push_back(3);
    nums2.push_back(4);
    nums2.push_back(2);

    vector<int> result = solution.nextGreaterElement(nums1, nums2);

    // Print the result
    cout << "Result of nextGreaterElement: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
