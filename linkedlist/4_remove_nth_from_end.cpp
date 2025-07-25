#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* first = &dummy;
    ListNode* second = &dummy;

    for (int i = 0; i <= n; ++i)
        first = first->next;
    
    while (first) {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    return dummy.next;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head = removeNthFromEnd(head, 1);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}
