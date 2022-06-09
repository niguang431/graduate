// https://leetcode.cn/problems/reverse-linked-list/
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
    // 迭代
    ListNode* reverseList_0(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // 递归
    ListNode* reverseList_1(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* new_head = reverseList_1(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }

    // 头插法
    ListNode* reverseList_2(ListNode* head) {
        ListNode* new_head = nullptr;
        ListNode* tmp = nullptr;
        if (!head || !head->next) {
            return head;
        }

        while (head) {
            tmp = head;
            head = head->next;
            tmp->next = new_head;
            new_head = tmp;
        }
        return new_head;
    }
};