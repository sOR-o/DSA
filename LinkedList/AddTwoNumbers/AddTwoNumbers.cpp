#include <bits/stdc++.h>
using namespace std;

// 2. Add Two Numbers

// // Given the head of a linked list, return the list after sorting it in ascending order.
// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. 
// Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example 1:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]

// Example 2:
// Input: l1 = [0], l2 = [0]
// Output: [0]

// Example 3:
// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void insert(ListNode*& head, ListNode*& tail, int val) {
        ListNode* temp = new ListNode(val);

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    ListNode* add(ListNode* first, ListNode* second) {
        int carry = 0;

        ListNode* anshead = NULL;
        ListNode* anstail = NULL;

        while (first != NULL || second != NULL || carry != 0) {
            int val1 = 0;
            int val2 = 0;
            if (first != NULL) val1 = first->val;
            if (second != NULL) val2 = second->val;

            int sum = carry + val1 + val2;
            int digit = sum % 10;
            insert(anshead, anstail, digit);
            carry = sum / 10;

            if (first != NULL) first = first->next;
            if (second != NULL) second = second->next;
        }
        return anshead;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* ans = add(l1, l2);

        ans = reverse(ans);
        return ans;
    }
};

int main() {
    // Example usage:
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Printing the result
    while (result != NULL) {
        std::cout << result->val;
        if (result->next) {
            std::cout << " -> ";
        }
        result = result->next;
    }
    std::cout << std::endl;

    // Free the memory to avoid memory leaks
    ListNode* temp;
    while (l1 != NULL) {
        temp = l1;
        l1 = l1->next;
        delete temp;
    }

    while (l2 != NULL) {
        temp = l2;
        l2 = l2->next;
        delete temp;
    }

    while (result != NULL) {
        temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
