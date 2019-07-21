/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode *removeElements(ListNode *head, int val)
    {
        auto p = head, q = head;
        while (p)
        {
            if (p->val == val)
            {
                if (p == head)
                {
                    head = p->next;
                    p = head;
                }
                else
                {
                    q->next = p->next;
                    p->next = nullptr;
                    p = q->next;
                }
            }
            else
            {
                q = p;
                p = p->next;
            }
        }
        return head;
    }
};
