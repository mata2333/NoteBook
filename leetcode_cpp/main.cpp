#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {};
};

class MyLinkedList {
    int size;
    ListNode* head;
public:
    MyLinkedList() {
        size = 0;
        head = new ListNode(0);
    }

    int get(int index) {
        ListNode* cur = head;
        int cur_index = 0;
        cur = cur->next;

        if (index >= size || index < 0) {
            return -1;
        }

        while (cur_index != index) {
            if (cur == nullptr) {
                return -1;
            }
            cur = cur->next;
            cur_index++;
        }
        if (cur)
            return cur->val;
        else
            return -1;
    }

    void addAtHead(int val) {
        ListNode* element = new ListNode(val);
        element->next = head->next;
        head->next = element;
        size++;
    }

    void addAtTail(int val) {
        ListNode* cur = head;
        // 遍历到尾节点
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        ListNode* node = new ListNode(val);
        cur->next = node;
        size++;
    }

    void addAtIndex(int index, int val) {
        ListNode* cur = head;
        int cur_index = 0;
        cur = cur->next;

        if (index == 0) {
            addAtHead(val);
            size++;
            return;
        }
        if (index == size) {
            addAtTail(val);
            size++;
            return;
        }
        if (index > size || index < 0) {
            return;
        }

        while (cur_index != index - 1 && cur != nullptr) {
            cur = cur->next;
            cur_index++;
        }
        ListNode* node = new ListNode(val);
        if (cur) {
            node->next = cur->next;
            cur->next = node;
            size++;
        }
    }

    void deleteAtIndex(int index) {
        ListNode* cur = head;
        int cur_index = 0;
        while (cur_index != index && cur) {
            cur = cur->next;
            cur_index++;
        }
        if (cur) {
            if (cur->next) {
                cur->next = cur->next->next;
                size--;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
    int arr[] = {92,23,40,78,57,56,20,12,83,21,51,56,9,76,8,73,31,80,37,33,92,16,1,14,17,84,23,8,80,2,23,53,90,17,98,19,24,12,43,17,9,21,50,28,79,83,40,40,45,33,70,42};

}
