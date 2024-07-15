#include <iostream>
#include <unordered_map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::unordered_map<ListNode*, int> map;
        ListNode* p = headA;
        while (p) {
            map[p]++;
            p = p->next;
        }
        p = headB;
        while (p) {
            if (map[p] != 0) {
                return p;
            }
            p = p->next;
        }
        return nullptr;
    }
};