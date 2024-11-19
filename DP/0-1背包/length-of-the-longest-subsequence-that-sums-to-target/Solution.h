#include <vector>
using namespace std;
class Solution {
public:
    vector<int> dp;

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        dp = vector<int>(target+1,-1);
        return dfs(nums,target,n-1);
    }

    int dfs(vector<int>& nums, int target, int i){
        if(target == 0){
            return 1;
        }else if(target < 0){
            return 0;
        }
        if(i < 0){
            return 0;
        }
        int& res = dp[target];
        if(res != -1){
            return res;
        }
        return res = max(dfs(nums,target-nums[i],i-1)+1,dfs(nums,target,i-1));
    }
};