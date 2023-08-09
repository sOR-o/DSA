#include <bits/stdc++.h>
using namespace std;

// 136. Single Number

// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its 
// next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.
// Given two integer arrays gas and cost, return the starting gas station's index if you can travel around 
// the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

// Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
// Output: 3

// Input: gas = [2,3,4], cost = [3,4,3]
// Output: -1


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int req = 0, index = 0, balance = 0;

        for (int i = 0; i < gas.size(); i++) {
            balance += (gas[i] - cost[i]);
            if (balance < 0) {
                req += balance;
                balance = 0;
                index = i + 1;
            }
        }
        if (balance + req >= 0)
            return index;
        return -1;
    }
};

int main() {
    Solution solution;

    // Using push_back to populate the gas and cost vectors
    vector<int> gas;
    gas.push_back(1);
    gas.push_back(2);
    gas.push_back(3);
    gas.push_back(4);
    gas.push_back(5);

    vector<int> cost;
    cost.push_back(3);
    cost.push_back(4);
    cost.push_back(5);
    cost.push_back(1);
    cost.push_back(2);

    int startingIndex = solution.canCompleteCircuit(gas, cost);

    cout << "Starting Index: " << startingIndex << endl;

    return 0;
}