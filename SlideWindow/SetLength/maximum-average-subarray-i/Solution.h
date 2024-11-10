#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        float sum = 0;
        int i = 0;
        for(i;i<k;i++){
            sum += nums[i];
        }
        float m = sum;
        for(i = k;i<nums.size();i++){
            sum = sum + nums[i] - nums[i-k];
            m = max(m,sum);
        }
        return m/k;

    }
};