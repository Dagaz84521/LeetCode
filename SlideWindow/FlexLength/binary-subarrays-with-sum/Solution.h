#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return SlideWindow(nums,goal+1) - SlideWindow(nums,goal);
    }

    int SlideWindow(vector<int>& nums, int k){
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int ans = 0;
        for(int right = 0; right < n; right++){
            sum += nums[right];
            while(sum >= k && left <= right){
                sum -= nums[left++];
            }
            ans += right - left + 1;
        }
        return ans;
    }
};
