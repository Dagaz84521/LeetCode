#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return SlideWindow(nums,k) - SlideWindow(nums,k+1);
    }

    int SlideWindow(vector<int>& nums, int k){
        int n = 0;
        int left = 0;
        int ans = 0;
        int num = 0;
        for(int right = 0; right < n; right++){
            num += (nums[right]%2==1)?1:0;
            while(num >= k){
                num -= (nums[left]%2==1)?1:0;
                left++;
            }
            ans += left;
        }
        return ans;
    }
};