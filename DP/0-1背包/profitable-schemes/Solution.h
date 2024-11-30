#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        int sum = accumulate(profit.begin(),profit.end(),0);
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));
        auto dfs = [&](auto&dfs, int n, int m, int p)->int{
            if(m < 0){
                if(p > 0)
                    return 0;
                else
                    return 1;
            }
                
            int& res = dp[m][n][p];
            if(res != -1)
                return res;
            int ans = 0;
            if(n >= group[m]){
                ans = (ans + dfs(dfs,n-group[m],m-1,max(0,p-profit[m]))) % MOD;
            }
            ans = (ans + dfs(dfs,n,m-1,p))%MOD;
            return res = ans;
        };
        int ans = dfs(dfs,n,m-1,minProfit);
        return ans;
    }
};