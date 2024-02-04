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


    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for(char c : t) need[c]++;

        int l = 0, r = 0, valid_char_nums =0;
        // record overlap index and length
        int start = 0, len = INT_MAX;
        while(r < s.size()){
            // c into window
            char c = s[r];
            // extend window
            r++;
            // update window
            if(need.count(c)){
                window[c]++;
                if(window[c] == need[c]){
                    valid_char_nums++;
                }
            }

            // check reduce window range by left
            while(valid_char_nums == need.size()){
                // update contains string
                if(r - l < len){
                    start = l;
                    len = r - l;
                }

                char remove_char = s[l];
                // reduce window
                l++;
                if(need.count(remove_char)){
                    if(window[remove_char] == need[remove_char]){
                        valid_char_nums--;
                    }
                    window[remove_char]--;
                }
            }
        }
        // the len
        return len == INT_MAX ? "" : s.substr(start, len);

    }
};

int main(){
    string s ="ADOBECODEBANC", t = "ABC";

}
