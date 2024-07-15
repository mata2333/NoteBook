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


int main() {
    int arr[] = {92,23,40,78,57,56,20,12,83,21,51,56,9,76,8,73,31,80,37,33,92,16,1,14,17,84,23,8,80,2,23,53,90,17,98,19,24,12,43,17,9,21,50,28,79,83,40,40,45,33,70,42};

}
