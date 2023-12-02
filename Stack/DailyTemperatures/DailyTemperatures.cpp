#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size(), 0);

        for(int i = temperatures.size()-1; i >= 0; i--) {
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]) st.pop();
            if(!st.empty()) ans[i] = st.top()-i;
            st.push(i);
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // Example usage with a sample vector of temperatures
    vector<int> temperatures;
    temperatures.push_back(73);
    temperatures.push_back(74);
    temperatures.push_back(75);
    temperatures.push_back(71);
    temperatures.push_back(69);
    temperatures.push_back(72);
    temperatures.push_back(76);
    temperatures.push_back(73);

    vector<int> result = solution.dailyTemperatures(temperatures);

    // Print the result
    cout << "Resulting vector of daily temperatures: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
