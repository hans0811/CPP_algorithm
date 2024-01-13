//
// Created by hans on 2024/1/10.
//
#include "tree_traverse.hpp"
#include "../utilites/TreeNode.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        int n = preorder.size();
        int m = inorder.size();

        TreeNode* root = build(preorder, 0, n-1, inorder, 0, m-1);

        return root;
    }

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd){
        if( preStart > preEnd || inStart > inEnd){
            cout << "into" << endl;
            return nullptr;
        }
        cout << preStart << endl;
        int rootVal = preorder[preStart];
        int index = 0;
        for(int i=inStart; i < inEnd; i++){
            if(inorder[i] == rootVal){
                index = i;
                break;
            }
        }

        int leftNum = index - inStart;

        TreeNode* root = new TreeNode(rootVal);
        root->left = build(preorder, preStart + 1, preEnd + leftNum, inorder, inStart, index -1);
        root->right = build(preorder, preStart + index + 1, preEnd, inorder, inStart+1, inEnd);
        return root;

    }

    void traverse_inorder(TreeNode* root){
        if(root){
            cout << root->val << " ";
            traverse_inorder(root->left);
            traverse_inorder(root->right);
        }
    }
};

int main(){
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<int> preorder={3,9,20,15,7};
    vector<int> inorder={9,3,15,20,7};

    Solution solution;
    TreeNode* res = solution.buildTree(preorder, inorder);

    solution.traverse_inorder(res);

    return 0;
}
