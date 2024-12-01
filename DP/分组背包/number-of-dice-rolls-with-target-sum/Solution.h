#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;
    int MOD = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        dp = vector<vector<int>>(n+1,vector<int>(target+1,-1));
        dfs(n-1,k,target);
        return dp[n-1][target];
    }

    int dfs(int n, int k, int target){
        if(n < 0){
            if(target == 0)
                return 1;
            else
                return 0;
        }
        int &res = dp[n][target];
        if(res != -1)
            return res;
        int sum = 0;
        for(int i = 1; i <= k; i++){    
            if(target >= i){
                sum += dfs(n-1,k,target-i);
                sum %= MOD;
            }
        }
        return res = sum;
    }
};