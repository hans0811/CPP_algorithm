//
// Created by hans on 2024/1/10.
//

#include "tree_traverse.hpp"
#include "../utilites/TreeNode.hpp"
#include <iostream>

using namespace std;


void traverse(TreeNode* root){
    if(root == nullptr) return;

    traverse(root->left);
    cout << root->val << endl;
    traverse(root->right);

}

int main(){
    // Create nodes
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    traverse(root);

}