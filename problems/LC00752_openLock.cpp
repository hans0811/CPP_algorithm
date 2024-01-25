//
// Created by hans on 2024/1/10.
//
#include "tree_traverse.hpp"
#include "../utilites/TreeNode.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>`

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
        unordered_set<string> deads;
        for(string s : deadends){
            deads.insert(s);
        }
        // record visited
        unordered_set<string> visited;
        queue<string> q;

        // USE BFS from begin
        int step = 0;
        q.push("0000");
        visited.insert("0000");

        while(!q.empty()){
            int sz = q.size();

            // Board
            for(int i=0; i < sz; i++){
                string cur = q.front();
                q.pop();
                cout << cur << endl;

                // if it is end
                if(deads.count(cur)){
                    continue;
                }
                if(cur == target){
                    return step;
                }

                for(int j=0; j < 4; j++){
                    string up = plusOne(cur, j);
                    if (!visited.count(up)) {
                        q.push(up);
                        visited.insert(up);
                    }
                    string down = minusOne(cur, j);
                    if(!visited.count(down)){
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            step++;
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
