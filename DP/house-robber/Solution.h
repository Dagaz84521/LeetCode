#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> dp;

    int rob(vector<int>& nums) {
        int n = nums.size();
        dp = vector<int>(n+1,-1);
        return dfs(nums, n-1);
    }

    int dfs(vector<int>& nums, int n){
        if(n < 0){
            return 0;
        }
        int &res = dp[n];
        if(res != -1){
            return res;
        }
        return res = max(dfs(nums, n-1),dfs(nums,n-2)+nums[n]);
    }
    
};