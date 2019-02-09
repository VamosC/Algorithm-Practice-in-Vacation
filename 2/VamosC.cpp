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
    	ListNode* l = NULL;
    	ListNode* tail;
    	ListNode* p;
    	int carry;
    	int sum;

    	carry = 0;
    	while(l1 && l2){
    		sum = l1->val + l2->val + carry;
    		carry = sum/10;
    		p = new ListNode(sum%10);
    		if(l == NULL)
    			l = p;
    		else
    			tail->next = p;
    		tail = p;
    		l1 = l1->next;
    		l2 = l2->next;
    	}

    	while(l1){
    		sum = l1->val + carry;
    		carry = sum/10;
    		p = new ListNode(sum%10);
    		tail->next = p;
    		tail = p;
    		l1 = l1->next;
    	}

    	while(l2){
    		sum = l2->val + carry;
    		carry = sum/10;
    		p = new ListNode(sum%10);
    		tail->next = p;
    		tail = p;
    		l2 = l2->next;
    	}

    	if(carry){
    		p = new ListNode(carry);
    		tail->next = p;
    	}

    	return l;
    }
};