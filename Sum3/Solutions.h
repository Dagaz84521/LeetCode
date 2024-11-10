#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size()-2;i++){
            int lft = i+1;
            int rit = nums.size()-1;
            while(rit > lft){
                if(nums[rit]+nums[lft]+nums[i] == 0){
                    res.push_back({nums[i],nums[lft],nums[rit]});
                    while(rit != lft && nums[rit] == nums[rit-1]) rit--;
                    while(rit != lft && nums[lft] == nums[lft+1]) lft++;
                    rit--;
                    lft++;
                }else if(nums[rit]+nums[lft]+nums[i] > 0){
                    rit--;
                }else if(nums[rit]+nums[lft]+nums[i] < 0){
                    lft++;
                }
            }
        }
        return res;
    }
};