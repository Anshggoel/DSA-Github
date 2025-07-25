#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++) {
        int rem = target - nums[i];
        if(mp.count(rem)) return {mp[rem], i};
        mp[nums[i]] = i;
    }
    return {};
}
int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = twoSum(nums, target);
    for(int i : res) cout << i << " ";
}
