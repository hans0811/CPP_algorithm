//
// Created by hans on 2024/1/10.
//
#include "tree_traverse.hpp"
#include "../utilites/TreeNode.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution{
public:

    string plusOne(string s, int j){
        char ch[s.length()];
        strcpy(ch, s.c_str());
        if(ch[j] == '9'){
            ch[j] = '0';
        }else{
            ch[j] += 1;
        }
        string res(ch);
        return res;
    }

    string minusOne(string s, int j){
        char ch[s.length()];
        strcpy(ch, s.c_str());
        if(ch[j] == '0'){
            ch[j] = '9';
        }else{
            ch[j] -= 1;
        }
        string res(ch);
        return res;
    }


    int openLock(vector<string>& deadends, string target) {
        // record deadends
        unordered_set<string> deads(deadends.begin(), deadends.end());
        unordered_set<string> q1, q2, visited;

        // USE BFS from begin
        int step = 0;
        q1.insert("0000");
        q2.insert(target);

        while(!q1.empty() && !q2.empty()){
            //
            unordered_set<string> temp;

            // Board
            for(auto cur : q1){
                if(deads.count(cur))
                    continue;
                if(q2.count(cur))
                    return step;

                visited.insert(cur);

                for(int j=0; j<4; j++){
                    string up = plusOne(cur, j);
                    if(!visited.count(up))
                        temp.insert(up);
                    string down = minusOne(cur, j);
                    if(!visited.count(down))
                        temp.insert(down);
                }

            }

            step++;
            q1 = q2;
            q2 = temp;

        }
        return -1;
    }
};

int main(){
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
}
