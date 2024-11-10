#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
        int i = nums.size()-1;
        for(i;i>0;i--){
            if(nums[i] > nums[i-1]){
                for(int j = nums.size()-1;j>=i;j--){
                    if(nums[j] > nums[i-1]){
                        swap(nums[j],nums[i-1]);
                        reverse(nums.begin()+j+1,nums.end());
                        break;
                    }
                }
            }
        }
        if(i == 0){
            reverse(nums.begin(),nums.end());
        }
    }
};