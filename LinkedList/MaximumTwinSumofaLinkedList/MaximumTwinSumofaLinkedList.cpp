#include <bits/stdc++.h>
using namespace std;

// 2130. Maximum Twin Sum of a Linked List

// In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, 
// if 0 <= i <= (n / 2) - 1.
// For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. 
// These are the only nodes with twins for n = 4.
// The twin sum is defined as the sum of a node and its twin.
// Given the head of a linked list with even length, return the maximum twin sum of the linked list.

// Example 1:
// Input: head = [5,4,2,1]
// Output: 6

// Example 2:
// Input: head = [4,2,2,3]
// Output: 7

// Definition for singly-linked list.

class ListNode {
public:
    int val;
    ListNode* next;
    
    ListNode(int value) : val(value), next(nullptr) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        std::stack<int> stk;
        
        // Push all elements of the linked list into the stack
        while (temp) {
            stk.push(temp->val);
            temp = temp->next;
        }
        
        int maxi = 0;
        while (!stk.empty() && head) {
            // Calculate the sum and update the maximum value
            maxi = std::max(maxi, stk.top() + head->val);
            head = head->next;
            stk.pop();
        }
        
        return maxi;
    }
};

int main() {
    // Create a linked list for demonstration purposes
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(2);

    Solution solution;
    int result = solution.pairSum(head);

    std::cout << "Maximum pair sum: " << result << std::endl;

    // Clean up the memory allocated for the linked list
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}