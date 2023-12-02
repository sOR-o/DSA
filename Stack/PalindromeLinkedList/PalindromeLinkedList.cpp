#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if(head == NULL || head->next == NULL) return true;

        vector<int> ans;
        ListNode* temp = head;
        while(temp){
            ans.push_back(temp->val);
            temp = temp->next;
        }

        int i = 0;
        int j = ans.size()-1;
        while(i < j){
            if(ans[i] != ans[j]) return false;
            i++;
            j--;
        }

        return true;
        
    }
};

int main() {
    Solution solution;

    // Test the isPalindrome function
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    bool result = solution.isPalindrome(head);

    // Print the result
    cout << "Result of isPalindrome: " << (result ? "true" : "false") << endl;

    // Clean up the memory (optional)
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
