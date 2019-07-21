/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        auto p = head;
        auto q = head->next;
        decltype(p) t;
        p->next = nullptr;
        while (q)
        {
            t = q;
            q = q->next;
            t->next = p;
            p = t;
        }
        return p;
    }
};
