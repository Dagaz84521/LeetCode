#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int left = 0, right = *max_element(candies.begin(),candies.end()) + 1;
        while(left + 1 < right){
            int mid = left + (right - left) / 2;
            if(Check(candies, k, mid)){
                left = mid;
            }else{
                right = mid;
            }
        }
        return left;
    }

    bool Check(vector<int>& candies, long long k, int n){
        for(int c : candies){
            k -= c / n;
        }
        if(k <= 0)
            return true;
        else
            return false;
    }
};