#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int negative = 0, positive = 0;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] >= 0){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        negative = left;
        left = 0, right = n - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] > 0){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        positive = n - left;
        return max(negative, positive);
    }
};