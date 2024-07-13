cmake_minimum_required(VERSION 3.22)
project(leetcode)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/include)
link_directories(/usr/lib)

add_executable(leetcode main.cpp 30_串联所有单词的子串.cpp 438_找到字符串中所有字母异位词.cpp 239_滑动窗口最大值.cpp 239_滑动窗口最大值.cpp 27_移除元素.cpp 27_移除元素.cpp
        977_有序数组的平方.cpp
        209_长度最小的子数组.cpp
        59_螺旋矩阵II.cpp
        59_螺旋矩阵II.cpp
        203_移除链表元素.cpp
        707_设计链表.cpp)
