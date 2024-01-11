//
// Created by hans on 2024/1/10.
//
#include "tree_traverse.hpp"
#include "../utilites/TreeNode.hpp"
#include <iostream>

using namespace std;

int res = INT_MIN;
int maxPathSum(TreeNode* root) {

    if(root == nullptr) return 0;
    int left = max(0, maxPathSum(root->left));
    int right = max(0, maxPathSum(root->right));

    // postorder
    res = max(res, left + right + root->val);
    return max(left, right) + root->val;

}

int main(){
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    maxPathSum(root);

    cout<< res << endl;
}
