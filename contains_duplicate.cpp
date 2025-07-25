#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for(int num : nums) {
        if(seen.count(num)) return true;
        seen.insert(num);
    }
    return false;
}

int main() {
    vector<int> nums = {1,2,3,4};
    cout << containsDuplicate(nums);
}
