//
// Created by hans on 2024/1/10.
//
#include "tree_traverse.hpp"
#include "../utilites/TreeNode.hpp"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution{
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);

        // root itself is the first level, so depth initialize as 1
        int depth = 1;

        while(!q.empty()){
            int sz = q.size();

            for(int i=0; i < sz; i++){
                TreeNode* cur = q.front();
                q.pop();

                if(cur->left == nullptr && cur->right == nullptr){
                    return depth;
                }

                if(cur->left != nullptr){
                    q.push(cur->left);
                }
                if(cur->right != nullptr){
                    q.push(cur->right);
                }
            }
            depth++;
        }
        return depth;
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
}
