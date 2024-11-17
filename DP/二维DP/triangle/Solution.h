#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < m; i++){
            for(int j = 0; j <= i; j++){
                if(j == 0)
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                else
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
            }
        }
        return *min_element(dp[m-1].begin(),dp[m-1].end());
    }
};