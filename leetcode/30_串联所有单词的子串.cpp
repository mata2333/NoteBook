#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 暴力解法
    vector<int> findSubstring2(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string, int> words_map;

        int n = words.size(), m = words[0].size();
        int slen = s.size();
        for (const string& word: words) {
            words_map[word]++;
        }

        for (int i = 0; i < slen - m * n + 1; ++i) {
            unordered_map<string, int> words_cnt = words_map;
            for (int j = 0; j < m * n; j += m) {
                string word = s.substr(i + j, m);
                if (--words_cnt[word] == 0) {
                    words_cnt.erase(word);
                }
            }
            if (words_cnt.empty()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
    // 滑动窗口
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int slen = s.size(), wlen = words.size(), wsize = words[0].size();
        map<string, int> words_map;
        for (int i = 0; i < wlen; ++i) {
            words_map[words[i]]++;
        }
        for (int i = 0; i < wsize; ++i) {
            map<string, int> cnt;
            for (int j = 0; j < wlen; j++) {
                cnt[s.substr(j * wsize + i, wsize)]++;
            }
            for (int j = i; j < slen - wlen * wsize + 1; j += wsize) {
                if (words_map == cnt) {
                    ans.push_back(j);
                }
                // 边界处理
                if (j >= slen - wlen * wsize) {
                    break;
                }
                string str = s.substr(j, wsize);
                if (--cnt[str] == 0) {
                    cnt.erase(str);
                }
                str = s.substr(j + wlen * wsize, wsize);
                cnt[str]++;
            }
        }
        return ans;
    }
};

