#include <vector>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int max = nums[0];
        int min = nums[n-1];
        int begin = 0, end = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] >= max){
                max = nums[i];
            }else{
                end = i;
            }
        }
        for(int j = n-1; j >= 0; j--){
            if(nums[j] <= min){
                min = nums[j];
            }else{
                begin = j;
            }
        }
        return end - begin + 1;
    }
};