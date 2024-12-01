#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;
    int waysToReachTarget(int target, vector<vector<int>> &types) {
        int n = types.size();
        dp = vector<vector<int>>(n,vector<int>(target+1,-1));
        dfs(target, types, n-1);
        return dp[n-1][target];
    }

    int dfs(int target, vector<vector<int>>& types, int i){
        if(i < 0){
            if(target == 0)
                return 1;
            else
                return 0;
        }
        int& res = dp[i][target];
        if(res != -1){
            return res;
        }
        int ans = 0;
        for(int j = 0; types[i][1]*j <= target && j <= types[i][0]; j++){
            ans += dfs(target - types[i][1]*j, types, i-1);
        }
        return res = ans;
    }

    int waysToReachTarget2(int target, vector<vector<int>> &types){
        int n = types.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){
                for(int k = 0; types[i-1][1]*k <= j && k <= types[i-1][0]; k++){
                    dp[i][j] += dp[i-1][j-types[i-1][1]*k];
                    dp[i][j] %= 1000000007;
                }
            }
        }
        return dp[n][target];
    }

    int waysToReachTarget3(int target, vector<vector<int>> &types){
        int n = types.size();
        vector<int> f(target+1,0);
        f[0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= target; j++){
                for(int k = 0; k <= types[i][0]; k++){
                    dp[i][j] += dp[i-1][j-types[i-1][1]*k];
                    dp[i][j] %= 1000000007;
                }
            }
        }
    }
};