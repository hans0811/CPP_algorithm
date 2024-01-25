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
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        // root itself is the first level, so depth initialize as 1
        int depth = 1;

        while (!q.empty()) {
            /**<向下扩展-200>
            <div class="img-content"><img src="/images/dijkstra/1.jpeg" class="myimage"/></div>
            */
            int sz = q.size();
            /*将当前队列中的所有节点向四周扩散*/
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                /*判断是否到达终点*/
                if (cur->left == nullptr && cur->right == nullptr)
                    return depth;
                /*将 cur 的相邻节点加入队列*/
                if (cur->left != nullptr)
                    q.push(cur->left);
                if (cur->right != nullptr)
                    q.push(cur->right);
            }
            /* 这里增加步数 */
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
