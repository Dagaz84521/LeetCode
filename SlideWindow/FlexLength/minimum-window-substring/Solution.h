#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;
        int less = 0;
        for(auto c : t) {
            if(need.find(c) == need.end()) 
                less++;
            need[c]++;
        }
        int n = s.size();
        int left = 0, right = 0;
        int ans_left = -1, ans_right = n;
        while(right < n){
            char c = s[right];
            need[c]--;
            if(need[c] == 0) less--;

            while(less == 0){
                if(right - left < ans_right - ans_left){
                    ans_left = left;
                    ans_right = right;
                }
                if(need.count(s[left])){
                    need[s[left]]++;
                    if(need[s[left]] > 0) less++;
                }
                left++;
            }
            right++;
        }
        return ans_left == -1 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }
};