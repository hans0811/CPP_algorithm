cmake_minimum_required(VERSION 3.23)
project(beginner)

set(CMAKE_CXX_STANDARD 17)

#add_executable(algorithm main.cpp utilites/TreeNode.hpp problems/tree_traverse.cpp problems/tree_traverse.hpp)

add_executable(beginner utilites/TreeNode.hpp  problems/LC00567_checkInclusion.cpp utilites/ListNode.cpp utilites/ListNode.hpp)

#add_executable(algorithm utilites/TreeNode.hpp problems/tree_traverse.cpp problems/tree_traverse.hpp)