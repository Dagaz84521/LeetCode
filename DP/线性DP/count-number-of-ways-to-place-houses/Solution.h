#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> dp;

    int countHousePlacements(int n) {
        int MOD = 1e9 + 7;
        dp.resize(n+1, -1);
        dp[0] = 2;
        if(n>0) dp[1] = 3;
        for(int i=2; i<=n; i++) {
            dp[i] = (dp[i-1] + dp[i-2] + 1) % MOD;
        }
        return ((long)dp[n] * dp[n]) % MOD;
    }
};