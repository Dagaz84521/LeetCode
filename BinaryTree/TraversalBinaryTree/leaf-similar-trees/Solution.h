#include<vector>
#include<iostream>
#include"../TreeNode.h"
using namespace std;
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        checkLeaf(root1,leaf1);
        checkLeaf(root2,leaf2);
        if(leaf1.size() != leaf2.size())
            return false;
        int i = 0;
        int n = leaf1.size();
        while(i < n && leaf1[i] == leaf2[i]){
            i++;
        }
        if(i == n)
            return true;
        else
            return false;
    }

    void checkLeaf(TreeNode* root, vector<int> leaf){
        if(!root)
            return;
        if(!root->left && !root->right)
            leaf.push_back(root->val);
        checkLeaf(root->left, leaf);
        checkLeaf(root->right,leaf);
    }
};