#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<char,string> number={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> letterCombinations(string digits) {
        queue<string> q; 
        if(digits.size() == 0) return {};
        q.push("");
        for(int i = 0; i < digits.size(); i++){
            string s = number[digits[i]];
            int size = q.size();
            for(int j = 0; j < size; j++){
                string temp = q.front();
                q.pop();
                for(int k = 0; k < s.size(); k++){
                    q.push(temp+s[k]);
                }
            }
        }
        vector<string> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};