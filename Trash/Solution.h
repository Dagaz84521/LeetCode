#include<vector>
#include<algorithm>
using namespace std;
//洛谷P1156
class Solution {
public:
    int solution(vector<int>& t, vector<int>& f, vector<int>& h, int D){
        int n = t.size();
        vector<vector<int>> dp(n,vector<int>(D+1,INT_MAX/2));
        auto dfs = [&](auto& dfs,int i, int t, int d)->int{
            //如果d<0,说明成功脱困
            if(d < 0)
                return t[i];
            //如果t<t[i],说明时间不够
            if(t < t[i])
                return 0;
            //如果i==n,说明已经遍历了所有垃圾
            if(i == n)
                return 0;
            int& res = dp[i][d];
            if(res != INT_MAX/2)
                return res;
            return res = min(dfs(dfs,i+1,t,d-h[i]),dfs(dfs,i+1,t+t[i],d));
        };
        int ans = dfs(dfs,0,10,D);
        return ans;
    }
};