
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* tmp = cur->next;
            if (tmp != nullptr && tmp->val == val) {
                cur->next = cur->next->next;
                delete tmp;
                continue;
            }
            cur = cur->next;
        }
        if (head != nullptr && head->val == val) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        return head;
    }
};