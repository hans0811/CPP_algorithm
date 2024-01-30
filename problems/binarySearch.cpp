//
// Created by hans on 2024/1/28.
//

#include "binarySearch.hpp"
#include <vector>

class binarySearch {

public:
    int binarySearch1(std::vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1; // Attention

        while(left <= right){
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

    int binarySearch_left_bound(std::vector<int>& nums, int target){
        int l = 0, r = nums.size() - 1;
        // close
        while(l <= r){
            int mid = l + (r-l) / 2;

        }
    }

};