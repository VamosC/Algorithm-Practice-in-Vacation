/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	auto p = l1;
    	auto q = l2;
    	auto c = 0;
    	ListNode* res = nullptr;
    	ListNode* t = nullptr;
    	while(p && q)
    	{
    		if(t)
    		{
    			t->next = new ListNode((p->val + q->val + c)%10);
    			t = t->next;
    		}
    		else
    		{
    			res = new ListNode((p->val + q->val + c)%10);
    			t = res;
    		}
    		c = (p->val + q->val + c) >= 10 ? 1 : 0;
    		p = p->next;
    		q = q->next;
    	}
    	while(p)
    	{
    		if(t)
    		{
    			t->next = new ListNode((p->val+c)%10);
    			t = t->next;
    		}
    		else
    		{
    			res = new ListNode((p->val+c)%10);
    			t = res;
    		}
    		c = p->val+c >= 10 ? 1 : 0;
    		p = p->next;
    	}
    	while(q)
    	{
    		if(t)
    		{
    			t->next = new ListNode((q->val+c)%10);
    			t = t->next;
    		}
    		else
    		{
    			res = new ListNode((q->val+c)%10);
    			t = res;
    		}
    		c = q->val+c >= 10 ? 1 : 0;
    		q = q->next;
    	}
    	if(c != 0)
    	{
    		t->next = new ListNode(c);
    	}
    	return res;
    }
};