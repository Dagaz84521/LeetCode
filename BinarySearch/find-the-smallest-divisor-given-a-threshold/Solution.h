#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int left = 0, right = n-1;
        while(left <= right){
            int mid = (left + right)/2;
            if(Check(nums,threshold,nums[mid])){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return CalResult(nums,nums[left]);
    }

    int CalResult(vector<int>& nums, int d){
        int sum = 0;
        for(int a : nums){
            sum += (a-1)/d + 1;
        }
        return sum;
    }

    bool Check(vector<int>& nums, int threshold, int divisor){
        int sum = 0;
        for(int a : nums){
            sum += ceil(a/divisor);
        }
        if(sum > threshold)
            return false;
        else 
            return true;
    }
};