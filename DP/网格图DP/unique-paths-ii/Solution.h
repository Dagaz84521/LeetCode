#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[1][1] = 1;
        if(obstacleGrid[0][0] == 1)
            return 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(obstacleGrid[i-1][j-1] == 1)
                    continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1] + dp[i][j];
            }
        }
        return dp[m][n];
    }
};