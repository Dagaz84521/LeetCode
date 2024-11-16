#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp_pos(n,0);
        vector<int> dp_neg(n,0);
        dp_pos[0] = max(0,nums[0]);
        dp_neg[0] = min(0,nums[0]);
        for(int i=1;i<n;i++){
            dp_pos[i] = max(dp_pos[i-1]+nums[i],0);
            dp_neg[i] = min(dp_neg[i-1]+nums[i],0);
        }
        return max(*max_element(dp_pos.begin(),dp_pos.end()),-*min_element(dp_neg.begin(),dp_neg.end()));
    }
};