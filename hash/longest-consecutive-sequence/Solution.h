#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash = unordered_set<int>(nums.begin(),nums.end());
        int result = 0;
        for(auto &i : nums){
            int current = i;
            if(hash.count(i-1))
                continue;
            else{
                while(hash.count(current+1)){
                    current++;
                }
                result = max(current-i+1,result);
            }
        }
        return result;
    }
};