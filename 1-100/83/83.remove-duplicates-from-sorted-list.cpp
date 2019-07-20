/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        auto p = head;
        auto q = head->next;
        while (q)
        {
            if (p->val == q->val)
            {
                q = q->next;
                p->next = nullptr;
            }
            else
            {
                p->next = q;
                p = q;
                q = q->next;
            }
        }
        return head;
    }
};
