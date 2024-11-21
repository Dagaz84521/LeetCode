#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        sort(rewardValues.begin(),rewardValues.end());
        int m = rewardValues[n-1];
        int sum = accumulate(rewardValues.begin(),rewardValues.end(),0);
        vector<vector<bool>> dp(n+1,vector<bool>(2*m,0));
        dp[0][0] = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<=2*m;j++){
                if(j<rewardValues[i]){
                    dp[i+1][j+rewardValues[i]] = dp[i][j];
                }
                    dp[i+1][j] = dp[i][j] || dp[i+1][j];
            }
        }
        int ans = 0;
        for(int j=0;j<=2*m-1;j++){
            if(dp[n][j]){
                ans = j;
            }
        }
        return ans;
    }        

    int maxTotalReward2(vector<int>& rewardValues) {
        int n = rewardValues.size();
        sort(rewardValues.begin(),rewardValues.end());
        int m = rewardValues[n-1];
        int sum = accumulate(rewardValues.begin(),rewardValues.end(),0);
        vector<bool> dp(2*m,0);
        dp[0] = 1;
        for(int j = 0; j < 2*m; j++){
            for(int i = 0; i < n; i++){
                if(j < rewardValues[i]){
                    dp[j+rewardValues[i]] = dp[j] || dp[j+rewardValues[i]];
                }
            }
        }
        int ans = 0;
        for(int j = 0; j < 2*m; j++){
            if(dp[j]){
                ans = j;
            }
        }
    }
};