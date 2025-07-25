#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while(left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    reverseArray(arr);
    for(int n : arr) cout << n << " ";
}
