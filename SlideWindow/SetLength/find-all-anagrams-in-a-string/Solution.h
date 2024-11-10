#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>need,window;
        for(char c : p){
            need[c]++;
        }
        int left=0, right=0;
        vector<int> result;
        while(right < s.size()){
            char c = s[right];
            right++;
            window[c]++;
            while(window[c] > need[c]){
                char d = s[left];
                left++;
                window[d]--;
            }
            if(right - left == p.size()){
                result.push_back(left);
            }
        }
        return result;
    }
};