#include<vector>
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:
        vector<vector<int>> dp;
        int m,n;
        int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
            m = grid.size();
            n = grid[0].size();
            dp = vector<vector<int>>(n, vector<int>(m, 0));
            int ans = INT_MAX;
            for(int i = 0; i < n; i++){
                int res = dfs(grid, moveCost, 0, i);
                ans = min(ans, res);
            }
            return ans;
        }

        int dfs(vector<vector<int>>& grid, vector<vector<int>>& moveCost, int x, int y){
            if(x == m-1)    
                return grid[x][y];
            int& res = dp[x][y];
            if(res)
                return res;
            res = INT_MAX;
            for(int i = 0; i < n; i++){
                res = min(res, moveCost[grid[x][y]][i] + dfs(grid, moveCost, x+1, i));
            }
            res += grid[x][y];
            return res;
        }
};