#include <bits/stdc++.h>
using namespace std;

// 25. Reverse Nodes in k-Group

// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
// k is a positive integer and is less than or equal to the length of the linked list. 
// If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// Example 1:
// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

// Example 2:
// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)
            return NULL;

        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int count = 0;

        // Check if there are at least k nodes remaining in the list
        ListNode* ptr = head;
        for (int i = 0; i < k; i++) {
            if (ptr == NULL)
                return head;
            ptr = ptr->next;
        }

        // Reverse k nodes
        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Recursively reverse the rest of the list in groups of k
        if (next != NULL)
            head->next = reverseKGroup(next, k);

        return prev;
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
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution solution;
    ListNode* result = solution.reverseKGroup(head, k);

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