#include <iostream>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        stack<int> stk;
        while(temp) {
            stk.push(temp-> val);
            temp = temp-> next;
        }
        int maxi = 0;
        while(stk.size()){
            maxi = max(maxi, stk.top() + head-> val);
            head = head-> next;
            stk.pop();
        }
        return maxi;
    }
};

int main() {
    Solution solution;

    // Creating a sample linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Calling the pairSum function
    int result = solution.pairSum(head);

    // Printing the result
    cout << "Result of pairSum: " << result << endl;

    // Clean up the memory (optional)
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
