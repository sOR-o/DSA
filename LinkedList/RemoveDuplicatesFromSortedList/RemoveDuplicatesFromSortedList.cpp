#include <bits/stdc++.h>
using namespace std;

// Leetcode 83. Remove Duplicates from Sorted List


// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
//Return the linked list sorted as well.

// Example 1:
// Input: head = [1,1,2]
// Output: [1,2]

// Example 2:
// Input: head = [1,1,2,3,3]
// Output: [1,2,3]

// Definition of the ListNode structure
//  Definition of the ListNode structure
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};

int main() {
    // Create a sample linked list
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(3);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Create an instance of the Solution class
    Solution solution;

    // Call the deleteDuplicates function
    ListNode* result = solution.deleteDuplicates(head);

    // Print the modified linked list
    ListNode* curr = result;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    // Clean up the memory
    curr = result;
    while (curr != nullptr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}