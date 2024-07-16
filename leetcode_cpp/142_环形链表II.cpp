//
// Created by 16517 on 2024/7/16.
//
#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> map;
        ListNode* p = head;
        while(p) {
            if (map[p] == 1) {
                return p;
            }
            map[p]++;
            p = p->next;
        }
        return NULL;
    }
};