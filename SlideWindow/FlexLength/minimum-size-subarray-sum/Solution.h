#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int sum = 0;
        int ans = n;

        if(accumulate(nums.begin(),nums.end(),0) < target)
            return 0;

        while(right < n){
            sum += nums[right];

            while(sum >= target){
                ans = min(ans, right-left+1);
                sum -= nums[left];
                left--;
            }
            right++;
        }
        return ans;
    }
};