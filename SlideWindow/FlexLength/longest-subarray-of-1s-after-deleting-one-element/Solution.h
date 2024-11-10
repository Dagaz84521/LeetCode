#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        unordered_map<int,int> window;
        int n = nums.size();
        int right = 0, left = 0;
        int result = 0;
        while(right < n){
            window[nums[right]]++;

            while(window[0]>1){
                window[nums[left]]--;
                left++;
            }
            right++;
            result = max(window[1],result);
        }
        return result;
    }
};