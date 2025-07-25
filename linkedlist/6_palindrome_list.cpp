#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

bool isPalindrome(ListNode* head) {
    stack<int> s;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        s.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast) slow = slow->next;
    while (slow) {
        if (s.top() != slow->val) return false;
        s.pop();
        slow = slow->next;
    }
    return true;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    cout << isPalindrome(head);
}
