#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* merge(ListNode* l1, ListNode* l2) {
    if (!l1 || !l2) return l1 ? l1 : l2;
    if (l1->val < l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* mid = slow->next;
    slow->next = nullptr;
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);
    return merge(left, right);
}

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    head = sortList(head);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}
