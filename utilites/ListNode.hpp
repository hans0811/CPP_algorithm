//
// Created by hans on 2024/1/16.
//

#include <iostream>

#ifndef BEGINNER_LISTNODE_HPP
#define BEGINNER_LISTNODE_HPP

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    void printList(){
        ListNode* current = this;
        while(current != nullptr){
            std::cout << current-> val << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

};


#endif //BEGINNER_LISTNODE_HPP
