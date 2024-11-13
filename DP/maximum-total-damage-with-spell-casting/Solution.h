#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    long long maximumTotalDamage(vector<int> &power)
    {
        //哈希表，用于记录不同伤害值的数量
        unordered_map<int, int> mp; 
        int n = power.size();
        for (auto x : power)
        {
            mp[x]++;
        }
        //将哈希表转换为数组，并按伤害值从小到大排序
        vector<pair<int, int>> a(mp.begin(), mp.end());
        sort(a.begin(), a.end());
        n = a.size();
        //dp[i]表示前i个伤害值的最大伤害值和
        vector<long long> dp(n + 1);
        dp[0] = (long long)a[0].first * a[0].second;

        for (int i = 1; i < n; i++)
        {
            int x = a[i].first;//当前伤害值大小
            int y = a[i].second;//当前伤害值数量
            int j = i - 1;//j指向前面可以选择的伤害值
            //找到前面可以选择的伤害值
            while (j >= 0 && a[j].first + 2 >= x)
            {
                j--;
            }
            //更新dp[i]
            if (j == -1)//如果前面没有可以选择的伤害值，则到i时最大的伤害就是自身
            {
                dp[i] = max(dp[i - 1], (long long)x * y);
            }
            else //否则，dp[i]等于dp[j]+当前伤害值和
            {
                dp[i] = max(dp[i - 1], dp[j] + (long long)x * y);
            }
        }
        return dp[n - 1];
    }
};