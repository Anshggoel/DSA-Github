#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    deleteNode(head);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}
