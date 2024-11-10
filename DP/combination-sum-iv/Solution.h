#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> dp;

    int dfs(vector<int>& nums, int target){
        if(target == 0) 
            return 1;
        int &res = dp[target];
        if(res != -1) return res;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(target >= nums[i]){
                sum += dfs(nums, target - nums[i]);
            }
        }
        res = sum;
        return res;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        dp = vector<int>(target + 1, -1);
        return dfs(nums, target);
    }
};