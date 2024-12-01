#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), l = s3.size();
        if(m+n != l)
            return false;
        vector<vector<int>> dp(n,vector<int>(m, -1));
        auto dfs = [&](auto& dfs, int i, int j, int k)->int{
            if(k < 0)
                return 1;
            if(i < 0){
                //判断余下的j
                for(int a = j; a >= 0; a--, k--){
                    if(s2[a] != s3[k])
                        return 0;
                }
                return 1;
            }
            if(j < 0){
                //判断余下的j
                for(int a = i; a >= 0; a--, k--){
                    if(s1[a] != s3[k])
                        return 0;
                }
                return 1;
            }
            int &res = dp[i][j];
            if(res != -1)
                return res;
            return res = (s1[i] == s3[k] && dfs(dfs,i-1,j,k-1)) || (s2[j] == s3[k] && dfs(dfs,i,j-1,k-1));
        };
        int a = dfs(dfs,n-1,m-1,l-1);
        return a > 0? true:false;
    }

    bool isInterleave2(string s1, string s2, string s3){
        int n = s1.size(), m = s2.size(), l = s3.size();
        if(m+n != l)
            return false;
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++){
            if(s1[i-1] == s3[i-1])
                dp[i][0] = dp[i-1][0];
        }
        for(int i = 1; i <= m; i++){
            if(s2[i-1] == s3[i-1])
                dp[0][i] = dp[0][i-1];
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                dp[i][j] = (s1[i-1] == s3[i+j-1] && dp[i-1][j]) || (s2[j-1] == s3[i+j-1] && dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};