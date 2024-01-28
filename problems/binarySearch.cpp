//
// Created by hans on 2024/1/28.
//

#include "binarySearch.hpp"
#include <vector>

class binarySearch {

public:
    int binarySearch1(std::vector<int>& nums, int target){
        int right = 0;
        int left = nums.size() - 1; // Attention

        while(right <= left){
            int mid = left + (left -right)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
        }
        return -1;
    }

};