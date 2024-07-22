//
// Created by 16517 on 2024/7/22.
//

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mapr;
        unordered_map<char, int> mapm;
        for (char c: ransomNote) {
            mapr[c]++;
        }
        for (char c: magazine) {
            mapm[c]++;
        }
        for (auto ele: mapr) {
            if (mapr[ele.first] > mapm[ele.first])
                return false;
        }
        return true;
    }
};
