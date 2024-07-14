

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode* pre = head;
        ListNode* tail = pre->next;
        ListNode* new_head = new ListNode(0);
        while (true) {
            pre->next = new_head->next;
            new_head->next = pre;
            if (!tail) {
                break;
            }
            pre = tail;
            tail = tail->next;
        }
        return new_head->next;
    }
};