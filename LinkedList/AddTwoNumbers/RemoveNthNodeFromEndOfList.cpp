#include <bits/stdc++.h>
using namespace std;

// Leetcode 19. Remove Nth Node From End of List


// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Example 1:
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

// Example 2:
// Input: head = [1], n = 1
// Output: []

// Example 3:
// Input: head = [1,2], n = 1
// Output: [1]

// Definition for singly-linked list.

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int val) : val(val), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || (head->next == nullptr && n == 1)){
            return nullptr;
        }

        ListNode* curr;
        int count = 0;
        for (curr = head; curr->next != nullptr; curr = curr->next){
            count++;
        }

        if (n - 1 == count){
            ListNode* w = head->next;
            w->next = head->next->next;
            delete head;
            return w;
        }

        ListNode* temp = head;
        ListNode* first = temp;
        ListNode* second = temp;

        for (int i = 0; i < n; i++){
            first = first->next;
        }

        while (first->next != nullptr){
            first = first->next;
            second = second->next;
        }

        ListNode* x = second->next;
        second->next = second->next->next;
        delete x;

        return head;
    }
};

int main(){
    Solution solution;

    // Example 1:
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    int n1 = 2;

    ListNode* result1 = solution.removeNthFromEnd(head1, n1);
    ListNode* curr1 = result1;
    while (curr1 != nullptr){
        std::cout << curr1->val << " ";
        curr1 = curr1->next;
    }
    std::cout << std::endl;

    // Example 2:
    ListNode* head2 = new ListNode(1);
    int n2 = 1;

    ListNode* result2 = solution.removeNthFromEnd(head2, n2);
    ListNode* curr2 = result2;
    while (curr2 != nullptr){
        std::cout << curr2->val << " ";
        curr2 = curr2->next;
    }
    std::cout << std::endl;

    // Example 3:
    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(2);
    int n3 = 1;

    ListNode* result3 = solution.removeNthFromEnd(head3, n3);
    ListNode* curr3 = result3;
    while (curr3 != nullptr){
        std::cout << curr3->val << " ";
        curr3 = curr3->next;
    }
    std::cout << std::endl;

    return 0;
}