#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        int s = reduce(nums.begin(), nums.end()) - abs(target);
        if (s < 0 || s % 2) {
            return 0;
        }
        s = s / 2;
        vector<vector<int>> dp(n+1, vector<int>(s + 1, 0));
        dp[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= s; j++){
                if(j >= nums[i]){
                    dp[i+1][j] = dp[i][j] + dp[i][j-nums[i]];
                }else{
                    dp[i+1][j] = dp[i][j];
                }
            }
        }
        return dp[n][s];
    }
};