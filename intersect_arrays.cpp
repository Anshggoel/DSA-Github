#include <bits/stdc++.h>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> m;
    for(int n : nums1) m[n]++;
    vector<int> result;
    for(int n : nums2) {
        if(m[n] > 0) {
            result.push_back(n);
            m[n]--;
        }
    }
    return result;
}

int main() {
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> result = intersect(nums1, nums2);
    for(int r : result) cout << r << " ";
}
