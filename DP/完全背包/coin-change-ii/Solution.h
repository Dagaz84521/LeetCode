#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp = vector<vector<int>>(n,vector<int>(amount+1,-1));
        return dfs(amount,coins,n-1);
    }

    int dfs(int amount, vector<int>& coins, int n){
        if(n < 0)
            return amount == 0 ? 1 : 0;
        int &res = dp[n][amount];
        if(res != -1){
            return res;
        }
        if(amount < coins[n]){
            return dfs(amount,coins,n-1);
        }
        return res = dfs(amount,coins,n-1) + dfs(amount-coins[n],coins,n);
    }

    int change2(int amount, vector<int>& coins){
        int n = coins.size();
        vector<vector<int>> f(n+1,vector<int>(amount+1,0));
        f[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= amount; j++){
                if(j >= coins[i])
                    f[i+1][j] += f[i+1][j-coins[i]];
                f[i+1][j] += f[i][j];
            }
        }
        int ans = f[n][amount];
        return ans;
    }

    int change3(int amount, vector<int>& coins){
        int n = coins.size();
        vector<unsigned> f(amount+1,0);
        f[0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = coins[i]; j <= amount; j++){
                f[j] += f[j-coins[i]];
            }
        }
        return f[amount];
    }
};