#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

    int rob(vector<int>& nums) {
        return max(rob(nums, 0, nums.size()-2), rob(nums, 1, nums.size()-1));
    }

    int rob(vector<int>& nums, int start, int end) {
        int f0 = 0;
        int f1 = 0;
        for(int i = start; i < end; i++) {
            int temp = max(f0 + nums[i], f1);
            f0 = f1;
            f1 = temp;
        }
        return f1;
    }
};