#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int MOD = 1e9 + 7;
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        if(m > n)
            return 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        auto dfs =[&](auto& dfs, int i, int j)->int{
            if(j < 0)
                return 1;
            else if(i < 0)
                return 0;
            int& res = dp[i][j];
            if(res != -1)
                return res;
            int ans = 0;
            if(s[i] != t[j]){
                ans = (ans + dfs(dfs,i-1,j)) % MOD;
            }else{
                ans = (ans + dfs(dfs,i-1,j-1)) % MOD;
                ans = (ans + dfs(dfs,i-1,j))%MOD;
            }
            return res = ans;
        };
        return dfs(dfs,n-1,m-1);
    }
};