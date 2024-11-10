#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
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
                    if (i > start && candidates[i] == candidates[i - 1])
                        continue;
                    path.push_back(candidates[i]);
                    dfs(candidates,target-candidates[i],path,result,i+1);
                    path.pop_back();
                }
            }
        }
    }
};