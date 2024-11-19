#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            q.push({i, 0});
        }
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(int i = max(x-1,0); i <= min(x+1,n-1); i++){
                if(y+1 >= m)
                    continue;
                if(grid[i][y+1] > grid[x][y]){
                    q.push({i, y+1});
                    res = max(res, y+1);
                }
            }
        }
        return res;
    }
};