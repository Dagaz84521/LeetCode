#include<vector>
using namespace std;
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,-INT_MAX/2));
        auto dfs = [&](auto& dfs, int i, int j)->int{
            if(i<0||j<0){
                return -INT_MAX/2;
            }
            int& res = dp[i][j];
            if(res > -INT_MAX/2){
                return res;
            }
            int ans = nums1[i]*nums2[j] + max(dfs(dfs,i-1,j-1),0);
            return res = max(ans,max(dfs(dfs,i-1,j),dfs(dfs,i,j-1)));
        };
        return dfs(dfs,n-1,m-1);
    }

    int maxDotProduct2(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MIN/2));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int ans = (nums1[i-1] * nums2[j-1]) + max(dp[i-1][j-1],0);
                dp[i][j] = max(ans,max(dp[i-1][j],dp[i][j-1]));
            }
        }

        return dp[n][m];
    }
};