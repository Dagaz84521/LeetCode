#include <iostream>
#include <vector>
#include"../TreeNode.h"
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum);
    }

    bool dfs(TreeNode* node, int target){
        if(target < 0)
            return false;

        if(node->left == node->right){
            if(target == 0)
                return true;
            else
                return false;
        }


        return dfs(node->left,target-node->val) || dfs(node->right,target-node->val);
    }
};