#include<iostream>
#include"../TreeNode.h"
using namespace std;
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root,0);
    }

    int dfs(TreeNode* node, int num){
        if(node == 0)
            return num;
        return dfs(node->left,num*2+node->val) + dfs(node->right,num*2+node->val);
    }
};