#include<vector>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int x : nums){
            sum += x;
        }
        if(sum % 2)
            return false;
        int target = sum / 2;
        vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= target; j++){
                if(nums[i-1] == j){
                    dp[i][j] = true;
                }else if((j>nums[i-1] && dp[i-1][j-nums[i-1]])||dp[i-1][j]){
                    dp[i][j] = true;
                }            
            }
        }
        for(int i = 1; i <= n; i++){
            if(dp[i][target])
                return true;
        }
        return false;
    }
};