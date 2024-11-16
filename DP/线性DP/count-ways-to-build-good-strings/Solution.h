#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> dp;
    int zero;
    int one;
    int low;
    int high;

    int countGoodStrings(int low, int high, int zero, int one) {
        this->zero = zero;
        this->one = one;
        this->low = low;
        this->high = high;
        dp = vector<int>(high + 1, -1);
        int sum = 0;
        for(int i = low; i <= high; i++){
            sum += dfs(i);
        }
        return sum;
    }

    int dfs(int n){
        if(n == 0)
            return 1;
        int &res = dp[n];
        if(res != -1) 
            return res;
        return res = dfs(n - zero) + dfs(n - one);
    }



};