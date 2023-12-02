#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{') {
                stk.push(ch);
            } else {
                if (!stk.empty()) {
                    char top = stk.top();
                    if (top == '(' && ch == ')' || top == '{' && ch == '}' || top == '[' && ch == ']') {
                        stk.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }

        return stk.empty();
    }
};

int main() {
    Solution solution;

    // Test the isValid function with different inputs
    string input1 = "()";
    bool result1 = solution.isValid(input1);
    cout << "Result of isValid: " << (result1 ? "true" : "false") << endl;

    string input2 = "()[]{}";
    bool result2 = solution.isValid(input2);
    cout << "Result of isValid: " << (result2 ? "true" : "false") << endl;

    string input3 = "(]";
    bool result3 = solution.isValid(input3);
    cout << "Result of isValid: " << (result3 ? "true" : "false") << endl;

    string input4 = "([)]";
    bool result4 = solution.isValid(input4);
    cout << "Result of isValid: " << (result4 ? "true" : "false") << endl;

    // Add more test cases as needed...

    return 0;
}
