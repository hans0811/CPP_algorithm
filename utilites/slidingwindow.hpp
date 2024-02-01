//
// Created by hans on 2024/2/1.
//

#ifndef BEGINNER_SLIDINGWINDOW_HPP
#define BEGINNER_SLIDINGWINDOW_HPP
#include <string>
#include <unordered_map>


class slidingwindow {

    void slidingWindow(std::string s){
        std::unordered_map<char, int> window;

        int l = 0, r = 0;
        while(r < s.size()){
            // c will be added in window
            char c = s[r];
            window.add(c)
        }

    }

};


#endif //BEGINNER_SLIDINGWINDOW_HPP
