#include <bits/stdc++.h>
using namespace std;

// 203. Remove Linked List Elements

// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.
// val == val, and return the new head.

// Example 1:
// Input: head = [1,2,6,3,4,5,6], val = 6
// Output: [1,2,3,4,5]

// Example 2:
// Input: head = [], val = 1
// Output: []


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return head;

        ListNode* node = head;
        while (node && node->next) {
            if (node->next->val == val)
                node->next = node->next->next;
            else
                node = node->next;
        }

        // Handle case where the head node itself needs to be removed
        if (head->val == val)
            head = head->next;

        return head;
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    while (head != NULL) {
        std::cout << head->val;
        if (head->next)
            std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage:
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    int val = 6;

    Solution solution;
    ListNode* result = solution.removeElements(head, val);

    // Printing the result
    printList(result);

    // Free the memory to avoid memory leaks
    ListNode* temp;
    while (result != NULL) {
        temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}