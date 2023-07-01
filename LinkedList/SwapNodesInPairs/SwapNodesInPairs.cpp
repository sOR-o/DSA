#include <bits/stdc++.h>
using namespace std;

// Leetcode 24. Swap Nodes in Pairs

// Given a linked list, swap every two adjacent nodes and return its head. 
// You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

// Example 1:
// Input: head = [1,2,3,4]
// Output: [2,1,4,3]

// Example 2:
// Input: head = []
// Output: []

// Example 3:
// Input: head = [1]
// Output: [1]

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* temp = head->next;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr && curr->next) {
            ListNode* next = curr->next;
            curr->next = next->next;
            next->next = curr;

            if (prev) prev->next = next;

            prev = curr;
            curr = curr->next;
        }

        return temp;
    }
};

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Create an instance of the Solution class
    Solution solution;

    // Call the swapPairs function on the linked list
    ListNode* newHead = solution.swapPairs(head);

    // Print the resulting linked list
    ListNode* current = newHead;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // Clean up the allocated memory
    current = newHead;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}