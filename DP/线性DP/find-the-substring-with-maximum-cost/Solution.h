#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int> mp;
        for(int i = 0; i < chars.size(); i++){
            mp[chars[i]] = vals[i];
        }
        int n = s.size();
        vector<int> dp(n, 0);
        if(mp.find(s[0]) == mp.end())
            dp[0] = s[0] - 'a' + 1;
        else
            dp[0] = max(mp[s[0]], 0);
        for(int i = 1; i < n; i++){
            if(mp.find(s[i]) == mp.end())
                dp[i] = dp[i-1] + s[i] - 'a' + 1;
            else
                dp[i] = max(dp[i-1]+mp[s[i]],0);
        }
        return *max_element(dp.begin(), dp.end());
    }
};