#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        int len = 0, curi = 1;
        while (p) {
            len++;
            p = p->next;
        }
        p = head;
        if (p && len == n) {
            ListNode* tmp = p;
            p = p->next;
            delete tmp;
            return p;
        }
        while (p) {
            if (curi == len - n && p->next) {
                ListNode* tmp = p->next;
                p->next = p->next->next;
                delete tmp;
                break;
            }
            curi++;
            p = p->next;
        }
        return head;
    }
};