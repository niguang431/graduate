// https://leetcode.cn/problems/reverse-nodes-in-k-group/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 翻转一个子链表，并且返回新的头与尾
    pair<ListNode*, ListNode*> myReverseIteration(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* curr = head;
        while (prev != tail) {
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return make_pair(tail, head);
    }

    pair<ListNode*, ListNode*> myReverseInsert(ListNode* head, ListNode* tail) {
        if (!head || !head->next) {
            return make_pair(head, tail);
        }

        ListNode* new_head = nullptr;
        ListNode* new_tail = head;
        ListNode* tmp = nullptr;
        while (head != tail) {
            tmp = head;
            head = head->next;
            tmp->next = new_head;
            new_head = tmp;
        }
        tail->next = new_head;
        new_head = tail;
        return make_pair(new_head, new_tail);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head) {
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;
            pair<ListNode*, ListNode*> result = myReverseInsert(head, tail);
            head = result.first;
            tail = result.second;
            // 把子链表重新接回原链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }
};
