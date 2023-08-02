#include <bits/stdc++.h>
using namespace std;

// 328. Odd Even Linked List

// Given the head of a singly linked list, group all the nodes with odd indices together followed 
// by the nodes with even indices, and return the reordered list.
// The first node is considered odd, and the second node is even, and so on.
// Note that the relative order inside both the even and odd groups should remain as it was in the input.
// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]

// Example 2:
// Input: head = [2,1,3,5,6,4,7]
// Output: [2,3,6,7,1,5,4]

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode* result = solution.oddEvenList(head);

    // Printing the modified linked list: 1 -> 3 -> 5 -> 2 -> 4
    ListNode* temp = result;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    // Clean up: Freeing memory
    temp = result;
    while (temp != NULL) {
        ListNode* current = temp;
        temp = temp->next;
        delete current;
    }

    return 0;
}