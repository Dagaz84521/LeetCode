#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> dp;

    int rob(vector<int>& nums) {
        int n = nums.size();
        dp = vector<int>(n+1,-1);
        dp[0] = nums[0];
        if(n == 1){
            return nums[0];
        }
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }

};