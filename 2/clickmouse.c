/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* Add(struct ListNode* l1, struct ListNode* l2, int carry);
    struct ListNode* p = Add( l1, l2, 0);
    return p;
}

struct ListNode* Add(struct ListNode* l1, struct ListNode* l2, int carry)
{
	if(l1 == NULL && l2 == NULL){
		if(carry == 0)
			return NULL;
		else{
			struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
			p->val = carry;
			p->next = NULL;
			return p;
		}
	}
	struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
	if(l1 != NULL && l2 != NULL){
		p->val = l1->val + l2->val + carry;
		if(p->val >= 10){
			p->val -= 10;
			carry = 1;
		}
		else
			carry = 0;
		p->next = Add( l1->next, l2->next, carry);
	}
	else if(l1 == NULL){
		p->val = l2->val + carry;
		if(p->val >= 10){
			p->val -= 10;
			carry = 1;
		}
		else
			carry = 0;
		p->next = Add( l1, l2->next, carry);
	}
	else if(l2 == NULL){
		p->val = l1->val + carry;
		if(p->val >= 10){
			p->val -= 10;
			carry = 1;
		}
		else
			carry = 0;
		p->next = Add( l1->next, l2, carry);
	}
	return p;
}
