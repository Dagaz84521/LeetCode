#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int ones(string s){
        int res = 0;
        for(auto c:s){
            if(c == '1'){
                res++;
            }
        }
        return res;
    }

    int zeroes(string s){
        int res = 0;
        for(auto c:s){
            if(c == '0'){
                res++;
            }
        }
        return res;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<vector<vector<int>>> dp(s+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        auto dfs = [&](auto& dfs, int i, int j, int k){
            if(i < 0){
                return 0;
            }
            int &res = dp[i][j][k];
            if(res != -1){
                return res;
            }
            if(j >= zeroes(strs[i]) && k >= ones(strs[i])){
                res = max(dfs(dfs,i-1,j-zeroes(strs[i]),k-ones(strs[i])+1)+1,dfs(dfs,i-1,j,k));
            }else{
                res = dfs(dfs,i-1,j,k);
            }
            return res;
        };
        return dfs(dfs,s-1,m,n);   
    }

    int findMaxForm2(vector<string>& strs, int m, int n){
        int s = strs.size();
        vector<vector<vector<int>>> dp(s+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        for(int i = 1; i <= s; i++){
            int ones = 0, zeroes = 0;
            cnt(strs[i-1],zeroes,ones);
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    if(j >= zeroes && k >= ones){
                        dp[i][j][k] = max(dp[i-1][j-zeroes][k-ones]+1,dp[i-1][j][k]);
                    }else{
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }
        return dp[s][m][n];
    }

    void cnt(string s, int& i, int& j){
        for(auto c:s){
            if(c == '0'){
                i++;
            }else{
                j++;
            }
        }
    }

    int findMaxForm3(vector<string>& strs, int m, int n){
        int s = strs.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 0; i < s; i++){
            int ones = 0, zeroes = 0;
            cnt(strs[i],zeroes,ones);
            for(int j = m; j >= zeroes; j--){
                for(int k = n; k >= ones; k--){
                    dp[j][k] = max(dp[j][k],dp[j-zeroes][k-ones]+1);
                }
            }
        }
        return dp[m][n];
    }
};