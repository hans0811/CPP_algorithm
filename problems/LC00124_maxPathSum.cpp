//
// Created by hans on 2024/1/10.
//
#include "tree_traverse.hpp"
#include "../utilites/TreeNode.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution{

public:
    int maxDepth(TreeNode* root){

        if(root == nullptr){
            return 0;
        }

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return 1 + max(leftDepth, rightDepth);
    }
    int ans = 0;
    int depth = 0;

    // 主函数
    int maxDepth1(TreeNode* root) {
        traverse(root);
        return ans;
    }

    // 二叉树遍历框架
    void traverse(TreeNode* root) {
        if (root == NULL) {
            // 到达叶子节点
            ans = max(ans, depth);
            return;
        }
        // 前序遍历位置
        depth++;
        traverse(root->left);
        traverse(root->right);
        // 后序遍历位置
        depth--;
    }

    // record all order
    vector<vector<int>> res;
    vector<int> track;

    vector<vector<int>> permute(vector<int>& nums){
        backtrack(nums);
        return res;
    }

    void backtrack(vector<int>& nums){
        if(track.size() == nums.size()){
            res.push_back(track);
            return;
        }

        for(int i=0; i < nums.size(); i++){
            if(std::find(track.begin(), track.end(), nums[i]) != track.end()){
                continue;
            }
            track.push_back(nums[i]);
            backtrack(nums);
            track.pop_back();
        }
    }

};

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
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);


    //maxPathSum(root);

    solution solution;

    int maxdepth = solution.maxDepth1(root);

    cout<< maxdepth << endl;
}
