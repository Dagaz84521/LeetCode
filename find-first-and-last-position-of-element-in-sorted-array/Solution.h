#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = 0, last = nums.size()-1;
        int left = 0, right = nums.size()-1;
        // find the first element
        while(left <= right){
            int mid = (left+right)/2;
            if(nums[mid]>=target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        if(left >= nums.size() || nums[left] != target){
            return {-1,-1};
        }
        first = left;
        left = 0;
        right = nums.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(nums[mid]>target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        last = right;
        return {first,last};
    }
};