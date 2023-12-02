#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<char> stt;
        string ans = "";

        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ']') stt.push(s[i]);
            else {
                string temp = "";
                int num = 0;
                int power = 1;

                while(!stt.empty() && stt.top() != '[') {
                    temp = stt.top() + temp;
                    stt.pop();
                }

                stt.pop();

                while(!stt.empty() && stt.top() >= '0' && stt.top() <= '9') {
                    num = power * (stt.top() - '0') + num;
                    power *= 10;
                    stt.pop();
                }

                string repeatedStr = "";
                for (int j = 0; j < num; j++) repeatedStr += temp;
                for (char ch : repeatedStr) stt.push(ch);
            }
        }
        while(!stt.empty()) {
            ans = stt.top() + ans;
            stt.pop();
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Test the decodeString function
    string input = "3[a]2[bc]";
    string result = solution.decodeString(input);

    // Print the result
    cout << "Result of decodeString: " << result << endl;

    return 0;
}
