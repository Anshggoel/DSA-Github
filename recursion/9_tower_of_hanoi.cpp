#include <iostream>
using namespace std;

void hanoi(int n, char src, char dest, char helper) {
    if (n == 0) return;
    hanoi(n - 1, src, helper, dest);
    cout << "Move disk " << n << " from " << src << " to " << dest << endl;
    hanoi(n - 1, helper, dest, src);
}

int main() {
    hanoi(3, 'A', 'C', 'B');
    return 0;
}
    