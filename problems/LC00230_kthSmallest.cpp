//
// Created by hans on 2024/1/10.
//
#include "tree_traverse.hpp"
#include "../utilites/TreeNode.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void inOrderTraversal(TreeNode* root, vector<int> &v){
        if(root == NULL) return;
        inOrderTraversal(root->left, v);
        v.push_back(root->val);
        inOrderTraversal(root->right, v);
    }

    int kthSmallest(TreeNode* root, int k){
        vector<int> v;
        inOrderTraversal(root, v);
        return v[k-1];
    }
};

int main(){
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    maxPathSum(root);

    cout<< res << endl;
}
