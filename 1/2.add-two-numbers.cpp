/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        auto p = l1;
        auto pre = p;
        int c = 0;
        while (l1 && l2)
        {
            if (l1->val + l2->val + c >= 10)
            {
                l1->val = (l1->val + l2->val + c) % 10;
                c = 1;
            }
            else
            {
                l1->val = (l1->val + l2->val + c) % 10;
                c = 0;
            }
            pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            if (l1->val + c >= 10)
            {
                l1->val = (l1->val + c) % 10;
                c = 1;
            }
            else
            {
                l1->val = (l1->val + c) % 10;
                c = 0;
            }
            pre = l1;
            l1 = l1->next;
        }
        while (l2)
        {
            if (l2->val + c >= 10)
            {
                pre->next = new ListNode((l2->val + c) % 10);
                c = 1;
            }
            else
            {
                pre->next = new ListNode((l2->val + c) % 10);
                c = 0;
            }
            pre = pre->next;
            l2 = l2->next;
        }
        if (c == 1)
        {
            pre->next = new ListNode(c);
        }
        return p;
    }
};
