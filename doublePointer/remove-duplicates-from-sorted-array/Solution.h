#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int j = i+1;
            while(nums[j] == nums[i] && j < nums.size()){
                nums.erase(nums.begin()+j,nums.begin()+j+1);
            }
        }
        return nums.size();
        vector<int> nums = vector<int>(n);
    }
};