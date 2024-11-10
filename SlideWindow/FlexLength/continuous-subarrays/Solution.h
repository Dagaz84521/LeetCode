#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> s;
        long long n = nums.size();
        long long left = 0;
        long long ans = 0;
        for(int right = 0; right < n; right++){
            s.insert(nums[right]);
            while(*s.rbegin() - *s.begin() > 2){
                s.erase(s.find(nums[left++]));
            }
            ans += right - left + 1;
        }

        return ans;
    }
};