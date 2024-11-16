#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> dp;

    int dfs(vector<int>& nums, int n){
        if(n < 0)
            return 0;
        int& res = dp[n];
        if(res != -1)
            return res;
        return res = max((dfs(nums,n-1)),0) + nums[n];
    }

    int maxSubArray1(vector<int>& nums) {//递归
        int n = nums.size();
        dp.resize(n+1, -1);
        dfs(nums,n-1);
        return *max_element(dp.begin(), dp.end()-1);
    }

    int maxSubArray2(vector<int>& nums){//递推
        int n = nums.size();
        dp.resize(n, 0);
        dp[0] = nums[0];
        for(int i = 1; i < n; i++){
            dp[i] = max(dp[i-1],0) + nums[i];
        }
        return *max_element(dp.begin(), dp.end());
    }

    int maxSubArray3(vector<int>& nums){//分治
        //参考Java版本
        return 0;
    }

     
};