#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_s = INT_MIN;
        int max_f = 0;
        int min_s = 0;
        int min_f = 0;
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            max_f = max(max_f,0)+nums[i];
            max_s = max(max_f,max_s);
            min_f = min(min_f,0) + nums[i];
            min_s = min(min_s,min_f);
            sum += nums[i];
        }
        return min_s == sum? max_s : max(max_s,sum-min_s);
    }
};