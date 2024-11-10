#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums[0]<=target){
            for(int i = 0; i < nums.size()-1;i++){
                if(nums[i] == target)
                    return i;
            }
        }else{
            for(int i = nums.size()-1; i >= 0 ;i--){
                if(nums[i] == target)
                    return i;
            }
        }
        return -1;
    }

    int search2(vector<int>& nums, int target){
        int n = nums.size();
        int left = 0, right = n-1;
        // find the smallest element
        int smallest = 0;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[0] > nums[mid]){
                right = mid-1;
                smallest = mid;
            }else{
                left = mid+1;
            }
        }
        left = smallest;
        right = smallest + n - 1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid%n] == target){
                return mid%n;
            }else if(nums[mid%n]<target){
                left = mid+1;
            }else if(nums[mid%n]>target){
                right = mid-1;
            }
        }
        return -1;
    }
};