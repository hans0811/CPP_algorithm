//
// Created by hans on 2024/1/10.
//

#include "tree_traverse.hpp"
#include "../utilites/TreeNode.hpp"
#include <iostream>

using namespace std;

// left -> root -> right
void traverse_inorder(TreeNode* root){
    if(root){
        traverse_inorder(root->left);
        cout << root->val << " ";
        traverse_inorder(root->right);
    }
}

// root -> left -> right
void traverse_preorder(TreeNode* root){
    if(root == nullptr) return;

    cout << root->val << " ";
    traverse_preorder(root->left);
    traverse_preorder(root->right);

}

// left -> right -> root
void traverse_postorder(TreeNode* root){
    if(root == nullptr) return;

    traverse_postorder(root->left);
    traverse_postorder(root->right);
    cout << root->val << " ";

}

int main(){
    // Create nodes
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << "Inorder" << endl;
    traverse_inorder(root);
    cout << "\nPreorder" << endl;
    traverse_preorder(root);
    cout << "\nPostorder" << endl;
    traverse_postorder(root);

}