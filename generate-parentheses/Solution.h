#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> res = {};

    vector<string> generateParenthesis(int n) {
        dfs("",0,0,n);
        return res;
    }

    void dfs(string path,int left,int right,int n){
        if(left == n && right == n){
            res.push_back(path);
            return;
        }
        if(left < n){
            dfs(path+"(",left+1,right,n);
        }
        if(right < left){
            dfs(path+")",left,right+1,n);
        }
    }
};