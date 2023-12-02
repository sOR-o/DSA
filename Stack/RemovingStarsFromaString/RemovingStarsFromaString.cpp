#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> stt;

        for(char chr : s) {
            if(chr != '*') stt.push(chr);
            else if(!stt.empty() && chr == '*') stt.pop();
        }

        if(stt.empty()) return "";

        string ans;
        while(!stt.empty()) { 
            ans.push_back(stt.top());
            stt.pop();
        }
        
        // reversing the string
        for(char chr : ans) stt.push(chr);
        ans.erase();

        while(!stt.empty()) { 
            ans.push_back(stt.top());
            stt.pop();
        }
        
        return ans;
    }
};

int main() {
    Solution solution;

    // Test the removeStars function
    string input = "a*b*c";
    string result = solution.removeStars(input);

    // Print the result
    cout << "Result of removeStars: " << result << endl;

    return 0;
}
