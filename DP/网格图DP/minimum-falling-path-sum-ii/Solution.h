#include<vector>
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        dp = vector<vector<int>>(n,vector<int>(n,0));
        int ans = INT_MAX;
        for(int j = 0; j < n; j++){
            int res = dfs(grid,0,j);
            ans = min(ans,res);
        }
        return ans;
    }

    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i == n-1)
            return grid[i][j];
        int &res = dp[i][j];
        if(res != 0)
            return res;
        res = INT_MAX;
        for(int k = 0; k < n; k++){
            if(k == j)
                continue;
            res = min(res,dfs(grid,i+1,k));
        }
        res += grid[i][j];
        return res;
    }
};