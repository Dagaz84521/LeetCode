#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(candidates,target,path,result,0);
        return result;
    }

    void dfs(vector<int>& candidates, int target, vector<int>& path, vector<vector<int>>& result, int start){
        if(target == 0){
            result.push_back(path);
            return;
        }else{
            for(int i=start;i<candidates.size();i++){
                if(target - candidates[i]>=0){
                    path.push_back(candidates[i]);
                    dfs(candidates,target-candidates[i],path,result,i);
                    path.pop_back();
                }
            }
        }
    }
};