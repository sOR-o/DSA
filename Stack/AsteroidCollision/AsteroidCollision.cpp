#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    bool checkSign(int num1, int num2) {
        if (num1 > 0 && num2 > 0) return true;
        if (num1 < 0 && num2 < 0) return true;
        return false;
    }

public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stt;
        vector<int> ans;

        for(int asteroid : asteroids) {
            while(!stt.empty() && !checkSign(stt.top(), asteroid)) {
                // edge case
                if(abs(stt.top()) < abs(asteroid) && asteroid/abs(asteroid) > stt.top()/abs(stt.top())) break;
                else if(abs(stt.top()) == abs(asteroid) && asteroid/abs(asteroid) > stt.top()/abs(stt.top())) break;
                else if(abs(stt.top()) > abs(asteroid) && asteroid/abs(asteroid) > stt.top()/abs(stt.top())) break;

                // normal case
                else if(abs(stt.top()) < abs(asteroid)) stt.pop();
                else if(abs(stt.top()) == abs(asteroid)) {
                    stt.pop();
                    asteroid = 0; 
                    break;
                }
                else {
                    asteroid = 0;
                    break;
                }
            }

            if(asteroid != 0) stt.push(asteroid);     
        }
        while (!stt.empty()) {
            ans.insert(ans.begin(), stt.top());
            stt.pop();
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Input vector of asteroids
    vector<int> asteroids;
    int n;
    cout << "Enter the number of asteroids: ";
    cin >> n;
    cout << "Enter the asteroids: ";
    for (int i = 0; i < n; ++i) {
        int asteroid;
        cin >> asteroid;
        asteroids.push_back(asteroid);
    }

    // Calculate asteroid collisions
    vector<int> result = solution.asteroidCollision(asteroids);

    // Print the result
    cout << "Resulting vector: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
