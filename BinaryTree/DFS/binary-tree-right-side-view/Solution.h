#include<iostream>
#include<vector>
#include"../TreeNode.h"
using namespace std;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root,result,0);
        return result;
    }

    void dfs(TreeNode* node, vector<int>& result, int cnt){
        if(!node)
            return;
        if(result.size() < cnt)
            result.push_back(node->val);
        else
            result[cnt] = node->val;
        dfs(node->left,result,cnt+1);
        dfs(node->right,result,cnt+1);
    }
};