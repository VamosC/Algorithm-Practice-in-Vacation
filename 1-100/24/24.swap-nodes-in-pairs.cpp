/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
auto static _ = []() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    return 0;
}();
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *p = head, *q = head;
        ListNode *pre = nullptr;
        ListNode *res = head;
        p = p->next;
        while (p != nullptr)
        {
            if (pre != nullptr)
                pre->next = p;
            q->next = p->next;
            p->next = q;
            if (res == head)
                res = p;
            pre = q;
            q = q->next;
            p = q;
            if (p != nullptr)
                p = p->next;
        }
        return res;
    }
};
// @lc code=end
