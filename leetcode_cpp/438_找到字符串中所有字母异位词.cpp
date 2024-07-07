//
// Created by admin on 2024/7/4.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    // 暴力解法
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> pmap;
        for (char i : p) {
            pmap[i]++;
        }
        for (int i = 0; i < s.size(); ++i) {
            unordered_map<char, int> cnt = pmap;
            for (int j = 0; j < p.size() && i + j < s.size(); ++j) {
                if (--cnt[s[i + j]] == 0) {
                    cnt.erase(s[i+j]);
                }
            }
            if (cnt.empty()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
    vector<int> findAnagrams2(string s, string p) {
        vector<int> ans;
        int plen = p.size(), slen = s.size();
        map<char, int> pmap;
        map<char, int> cnt;
        for (int i = 0; i < plen; ++i) {
            pmap[p[i]]++;
            cnt[s[i]]++;
        }

        for (int i = 0; i < slen - plen; ++i) {
            if (pmap == cnt) {
                ans.push_back(i);
            }
            if (--cnt[s[i]] == 0) {
                cnt.erase(s[i]);
            }
            cnt[s[i + plen]]++;
        }
        return ans;
    }
};