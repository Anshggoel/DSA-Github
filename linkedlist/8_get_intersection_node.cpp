#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

int getLength(ListNode* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

ListNode* getIntersectionNode(ListNode* a, ListNode* b) {
    int lenA = getLength(a), lenB = getLength(b);
    while (lenA > lenB) {
        a = a->next;
        lenA--;
    }
    while (lenB > lenA) {
        b = b->next;
        lenB--;
    }
    while (a && b && a != b) {
        a = a->next;
        b = b->next;
    }
    return a;
}

int main() {
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    ListNode* a = new ListNode(3);
    a->next = common;

    ListNode* b = new ListNode(5);
    b->next = new ListNode(6);
    b->next->next = common;

    ListNode* ans = getIntersectionNode(a, b);
    cout << (ans ? ans->val : -1);
}
