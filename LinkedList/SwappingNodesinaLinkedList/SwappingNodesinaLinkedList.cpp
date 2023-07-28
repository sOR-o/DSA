#include <bits/stdc++.h>
using namespace std;

// 1721. Swapping Nodes in a Linked List

// You are given the head of a linked list, and an integer k.
// Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end
// (the list is 1-indexed).

// Example 1:
// Input: head = [1,2,3,4,5], k = 2
// Output: [1,4,3,2,5]

// Example 2:
// Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
// Output: [7,9,6,6,8,7,3,0,9,5]

// Definition for singly-linked list.

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    
    ListNode(int value) : val(value), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* left = head;
        ListNode* right = head;
        ListNode* curr = head;

        int n = 1;
        while (curr != NULL) {
            if (n < k) left = left->next;
            if (n > k) right = right->next;

            curr = curr->next;
            n++;
        }
        
        std::swap(left->val, right->val);
        return head;
    }
};

// Function to print the linked list for demonstration
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // Create a linked list for demonstration purposes
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    int k = 2; // Replace this with the desired value of k

    cout << "Original linked list: ";
    printLinkedList(head);

    ListNode* result = solution.swapNodes(head, k);

    cout << "Linked list after swapping nodes at positions " << k << " and " << (k - 1) << ": ";
    printLinkedList(result);

    // Clean up the memory allocated for the linked list
    while (result != nullptr) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}