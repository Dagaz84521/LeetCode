#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    string largestNumber(vector<int> &cost, int target)
    {
        int n = cost.size();
        vector<string> dp(target + 1, "");
        for (int i = 1; i <= target; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i >= cost[j] && dp[i - cost[j]] != "" || i == cost[j])
                {
                    string s = dp[i - cost[j]] + to_string(j + 1);
                    if (s.size() > dp[i].size() || (s.size() == dp[i].size() && s > dp[i]))
                    {
                        dp[i] = s;
                    }
                }
            }
        }
        return dp[target].empty() ? "0" : dp[target];
    }
};