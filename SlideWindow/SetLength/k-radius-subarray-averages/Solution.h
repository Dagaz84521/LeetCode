#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result = vector<int>(n, -1);
        if(2*k+1 > n){
            return result;
        }
        long long sum = 0;
        for(int i = 0; i < 2*k+1; i++){
            sum += nums[i];
        }
        result[k] = sum/(2*k+1);
        for(int i = k+1; i < n-k; i++){
            sum = sum + nums[i+k] - nums[i-k-1];
            result[i] = sum/(2*k+1);
        }
        return result;
    }
};