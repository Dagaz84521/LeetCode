#include<cmath>
#include<vector>
using namespace std;
class Solution {
public:
    int p;

    int numberOfWays(int n, int x) {
        int MOD = 10^9+7;
        this->p = x;
        int m = find(n,1,n);
        vector<vector<int>> dp(m+1,vector<int>(n+2,0));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j <= n+1; j++){
                if(j >= pow(i+1,p)){
                    dp[i+1][j] = (dp[i][j] + dp[i][j-pow(i+1,p)]);
                }
                else{
                    dp[i+1][j] = dp[i][j];
                }
            }
        }
        return dp[m][n];
    }

    int find(int target,int l,int r){
        if(l>r)
            return l;
        int mid = (l+r)/2;
        if(pow(mid,p) > target)
            return find(target,l,mid-1);
        else if(pow(mid,p) <= target)
            return find(target,mid+1,r);
        else
            return mid;
    }
};