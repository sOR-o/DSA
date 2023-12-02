#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    vector<int> nextSmaller(vector<int>& heights) {
        stack<int> s;
        vector<int> ans(heights.size());
        s.push(-1);

        for(int i = heights.size()-1; i >= 0; i--) {
            int curr = heights[i];
            while(s.top() != -1 && heights[s.top()] >= curr) s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmaller(vector<int>& heights) {
        stack<int> s;
        vector<int> ans(heights.size());
        s.push(-1);

        for(int i = 0; i < heights.size(); i++) {
            int curr = heights[i];
            while(s.top() != -1 && heights[s.top()] >= curr) s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next = nextSmaller(heights);
        vector<int> prev = prevSmaller(heights);

        int ans = INT_MIN;

        for(int i = 0; i < heights.size(); i++) {
            int length = heights[i];
            if(next[i] == -1) next[i] = heights.size();
            int breadth = next[i] - prev[i]-1;

            int area = length * breadth;
            ans = max(ans, area);
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Test the largestRectangleArea function
    vector<int> heights;
    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(5);
    heights.push_back(6);
    heights.push_back(2);
    heights.push_back(3);

    
    int result = solution.largestRectangleArea(heights);

    // Print the result
    cout << "Result of largestRectangleArea: " << result << endl;

    return 0;
}
