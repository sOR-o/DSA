#include <bits/stdc++.h>
using namespace std;

// Leetcode 2095. Delete the Middle Node of a Linked List

// You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
// The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, 
// where ⌊x⌋ denotes the largest integer less than or equal to x.
// For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

// Example 1:
// Input: head = [1,3,4,7,1,2,6]
// Output: [1,3,4,1,2,6]

// Example 2:
// Input: head = [1,2,3,4]
// Output: [1,2,4]

// Example 3:
// Input: head = [2,1]
// Output: [2]

class ListNode {
public:
    int val;
    ListNode* next;
    
    ListNode(int val) : val(val), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) { 
            delete head;
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* back = NULL;

        while (fast != NULL && fast->next != NULL) {
            back = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        back->next = back->next->next;
        delete slow;
        return head;
    }
};

int main() {
    // Create the linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Print the original linked list
    cout << "Original Linked List: ";
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;

    // Call the deleteMiddle function of the Solution class
    Solution solution;
    head = solution.deleteMiddle(head);

    // Print the updated linked list
    cout << "Updated Linked List: ";
    current = head;
    while (current != NULL) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;

    // Clean up memory (delete the remaining nodes)
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}