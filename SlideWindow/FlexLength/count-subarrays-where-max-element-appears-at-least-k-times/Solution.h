#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long target = *max_element(nums.begin(),nums.end());
        long long left = 0;
        long long ans = 0;
        long long n = nums.size();
        long long cnt = 0;
        for(int right = 0; right < n; right++){
            if(nums[right] == target)
                cnt++;

            while(cnt >= k){
                if(nums[left] == target)
                    cnt--;
                left++;
            }
            ans += left;
        }
        return ans;
    }
};