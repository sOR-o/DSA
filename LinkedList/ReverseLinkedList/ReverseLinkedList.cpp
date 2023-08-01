#include <bits/stdc++.h>
using namespace std;

// 206. Reverse Linked List

// Given the head of a singly linked list, 
// reverse the list, and return the reversed list.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

// Example 2:
// Input: head = [1,2]
// Output: [2,1]

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedListFromArray(const int arr[], int size) {
    if (size <= 0) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    // Example usage:
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createLinkedListFromArray(arr, size);
    std::cout << "Original Linked List: ";
    printLinkedList(head);

    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);
    std::cout << "Reversed Linked List: ";
    printLinkedList(reversedHead);

    // Clean up the allocated memory to prevent memory leaks
    ListNode* current = reversedHead;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}