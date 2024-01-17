//
// Created by hans on 2024/1/10.
//


#include <iostream>
#include <vector>
#include "../../utilites/ListNode.hpp"

using namespace std;


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1), *p = dummy;
        ListNode* p1 = list1, *p2 = list2;
    }
};
int main(){

    // Create the first linked list: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));

    // Create the second linked list: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    list1->printList();
    list2->printList();


    return 0;
}
