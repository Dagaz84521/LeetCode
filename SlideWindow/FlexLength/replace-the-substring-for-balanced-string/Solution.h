#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> count = {{'Q', 0}, {'W', 0}, {'E', 0}, {'R', 0}};
        int n = s.size();
        int k = n / 4;
        int left = 0, right = 0;
        int ans = n;
        for (int i = 0; i < n; i++) {
            count[s[i]]++;
        }
        if(count['Q'] == k && count['W'] == k && count['E'] == k && count['R'] == k) {
            return 0;
        }
        while(right < n){
            count[s[right]]--;

            while(count['Q'] <= k && count['W'] <= k && count['E'] <= k && count['R'] <= k){
                ans = min(ans, right - left + 1);
                count[s[left]]++;
                left++;
            }

            right++;
        }
        return ans;

    }
};