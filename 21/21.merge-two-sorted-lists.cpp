/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *res = nullptr;
        ListNode *p;
        while (l1 && l2)
        {
            if (res)
            {
                if (l1->val < l2->val)
                {
                    p->next = new ListNode(l1->val);
                    p = p->next;
                    l1 = l1->next;
                }
                else
                {
                    p->next = new ListNode(l2->val);
                    p = p->next;
                    l2 = l2->next;
                }
            }
            else
            {
                if (l1->val < l2->val)
                {
                    res = new ListNode(l1->val);
                    p = res;
                    l1 = l1->next;
                }
                else
                {
                    res = new ListNode(l2->val);
                    p = res;
                    l2 = l2->next;
                }
            }
        }
        while (l1)
        {
            if (res)
            {
                p->next = new ListNode(l1->val);
                p = p->next;
                l1 = l1->next;
            }
            else
            {
                res = new ListNode(l1->val);
                p = res;
                l1 = l1->next;
            }
        }
        while (l2)
        {
            if (res)
            {
                p->next = new ListNode(l2->val);
                p = p->next;
                l2 = l2->next;
            }
            else
            {
                res = new ListNode(l2->val);
                p = res;
                l2 = l2->next;
            }
        }
        return res;
    }
};
