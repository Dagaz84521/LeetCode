#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp = vector<vector<int>>(n,vector<int>(amount+1,-1));
        return dfs(coins,amount,n-1);
    }

    int dfs(vector<int>& coins, int amount, int n){
        if(n < 0){
            if(amount == 0)
                return 0;
            else 
                return INT_MAX/2;
        }
        int& res = dp[n][amount];
        if(res != -1){
            return res;
        }
        if(amount < coins[n]){
            return res = dfs(coins,amount,n-1);
        }
        return res = max(dfs(coins,amount,n-1), dfs(coins,amount-coins[n],n)+1);
    }

    int coinChange2(vector<int>& coins, int amount){
        int n = coins.size();
        vector<vector<int>> f(vector<vector<int>>(n+1,vector<int>(amount+1,0)));
        for(int j = 1; j <= amount; j++){
            f[0][j] = INT_MAX/2;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= amount; j++){
                if(j < coins[i])
                    f[i+1][j] = f[i][j];
                else{
                    f[i+1][j] = min(f[i+1][j-coins[i]]+1,f[i][j]);
                }
            }
        }
        int ans = 0;
        if(f[n][amount] >= INT_MAX/2){
            ans = -1;
        }else{
            ans = f[n][amount];
        }
        return ans;
    }

    int coinChange3(vector<int>& coins, int amount){
        int n = coins.size();
        vector<int> f(amount+1,INT_MAX/2);
        f[0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= amount - coins[i]; j++){
                if(f[j] >= INT_MAX/2)
                    continue;
                f[j+coins[i]] = min(f[j+coins[i]],f[j]+1);
            }
        }
        return f[amount] < INT_MAX/2 ? f[amount] : -1;
    }
};