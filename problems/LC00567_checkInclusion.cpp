//
// Created by hans on 2024/1/10.
//
#include "tree_traverse.hpp"
#include "../utilites/TreeNode.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>


using namespace std;

class Solution{
public:


    bool minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for(char c : t) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        while( right < s.size()){
            char c = s[right];
            right++;

            if(need.count(c)){
                window[c]++;
            }
        }



        for(const auto& entry: need){
            cout<< entry.first << ": " << entry.second << endl;
        }

        cout << "test" << endl;
        return false;

    }
};

int main(){
    string s ="ab", t = "eidbaooo";

    Solution solution;


    cout << solution.minWindow(s, t) << endl;

}
