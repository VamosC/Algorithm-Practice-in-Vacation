/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr)
            return head;
        ListNode *p = head, *q = head;
        ListNode *pre = nullptr;
        while (n > 0 && q != nullptr)
        {
            q = q->next;
            n--;
        }
        if (n != 0)
            return head;
        while (q != nullptr)
        {
            pre = p;
            p = p->next;
            q = q->next;
        }
        if (pre == nullptr)
            return head->next;
        else
        {
            pre->next = p->next;
        }
        return head;
    }
};
// @lc code=end
