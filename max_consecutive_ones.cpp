#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0, maxCount = 0;
    for(int num : nums) {
        if(num == 1) count++;
        else count = 0;
        maxCount = max(maxCount, count);
    }
    return maxCount;
}

int main() {
    vector<int> nums = {1,1,0,1,1,1};
    cout << findMaxConsecutiveOnes(nums);
}
