#include<iostream>
#include"../TreeNode.h"
using namespace std;
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* t = new TreeNode(val);
            t->left = root;
            return t;
        }
        dfs(root, val, depth-1);
        return root;
    }

    void dfs(TreeNode* node, int val, int depth){
        if(node == nullptr) return;
        if(depth == 1){
            TreeNode* l = new TreeNode(val);
            TreeNode* r = new TreeNode(val);
            l->left = node->left;
            node->left = l;
            r->right = node->right;
            node->right = r;
            return;
        }else{
            dfs(node->left,val,depth-1);
            dfs(node->right,val,depth-1);
        }
    }
};