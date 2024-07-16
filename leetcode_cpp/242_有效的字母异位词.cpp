//
// Created by 16517 on 2024/7/16.
//
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;


class Solution {
public:
//    bool isAnagram(string s, string t) {
//        map<char, int> map1, map2;
//        for (char i : s) {
//            map1[i]++;
//        }
//        for (char i : t) {
//            map2[i]++;
//        }
//        if (map1 == map2)
//            return true;
//        return false;
//    }
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        for (char i : s) {
            map[i]++;
        }
        for (char i : t) {
            map[i]--;
        }
        for (auto it : map) {
            if (it.second != 0)
                return false;
        }
        return true;
    }
};