#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for(auto &s : strs){
            string sorted_s = s;
            sort(sorted_s.begin(),sorted_s.end());
            m[sorted_s].push_back(s);
        }
        vector<vector<string>> result;
        for(auto &[r,value] : m){
            result.push_back(value);
        }
        return result;
    }
};