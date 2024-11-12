#include<iostream>
#include<vector>
#include<algorithm>
#include<ranges>
using namespace std;
class Solution {
public:
    vector<int> dp;

    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int tmp = ranges::max(nums);
        vector<int> cnt(tmp + 1);
        vector<int> f(tmp + 1);
        for(int i : nums)
            cnt[i]++;
        f[1] = cnt[1];
        for(int i = 2; i <= tmp;i++)
            f[i] = max(f[i - 1], f[i - 2] + i * cnt[i]);
        return f[tmp];
    }
};