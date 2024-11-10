#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int left=0, right=0;
        int target = accumulate(nums.begin(),nums.end(),0) - x;
        int ans = 0;
        if(target<0)
            return -1;
        if(target == 0)
            return n;
        while(right < n){
            target -= nums[right];

            while(target < 0 && left <= right){
                target += nums[left];
                left++;
            }
            if(target == 0)
                ans = max(ans,right-left+1);
            right++; 
        }
        if(ans == 0)
            return -1;
        return n - ans;
    }
};