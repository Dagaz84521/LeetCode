#include <vector>
using namespace std;
class Solution
{
public:
    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int sum1 = 0, sum2 = 0;
        vector<int> diff1(n);
        vector<int> diff2(n);
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        for (int i = 0; i < n; i++)
        {
            diff2[i] = nums1[i] - nums2[i];
            diff1[i] = nums2[i] - nums1[i];
            sum1 += nums1[i];
            sum2 += nums2[i];
        }
        dfs(diff1, n - 1,dp1);
        dfs(diff2, n - 1,dp2);
        int res1 = *max_element(dp1.begin(), dp1.end());
        int res2 = *max_element(dp2.begin(), dp2.end());
        return max(res1 + sum1, res2 + sum2);
    }

    int dfs(vector<int> &diff, int i, vector<int> &dp)
    {
        if (i == 0)
        {
            return max(diff[0],0);
        }
        int &res = dp[i];
        if (res != -1)
        {
            return res;
        }
        return res = max(dfs(diff, i - 1,dp) + diff[i], 0);
    }
};