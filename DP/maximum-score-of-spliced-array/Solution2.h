#include <vector>
using namespace std;
class Solution{
    public:
    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2){
        int n = nums1.size();
        int sum1 = 0, sum2 = 0;
        vector<int> diff1(n);
        vector<int> diff2(n);
        for (int i = 0; i < n; i++)
        {
            diff2[i] = nums1[i] - nums2[i];
            diff1[i] = nums2[i] - nums1[i];
            sum1 += nums1[i];
            sum2 += nums2[i];
        }

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        dp1[0] = max(diff1[0],0);
        dp2[0] = max(diff2[0],0);
        for(int i = 1; i < n; i++){
            dp1[i] = max(dp1[i-1] + diff1[i], 0);
            dp2[i] = max(dp2[i-1] + diff2[i], 0);
        }
        int res1 = *max_element(dp1.begin(), dp1.end());
        int res2 = *max_element(dp2.begin(), dp2.end());
        return max(res1 + sum1, res2 + sum2);
    }
};