/**
* Definition for singly-linked list.
**/
#include <stdio.h>
#include <malloc.h>
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode * rst = NULL, *p = NULL, *last = NULL;
		int carry=0;
		while (l1 != NULL && l2 != NULL)
		{
			if (rst == NULL)
			{
				rst = new ListNode((l1->val + l2->val + carry) % 10);
				carry = (l1->val + l2->val+carry) / 10;
				last = rst;
			}
			else
			{
				p = new ListNode((l1->val + l2->val + carry) % 10);
				carry = (l1->val + l2->val + carry) / 10;
				last->next = p;
				last = p;
			}
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1!=NULL)
		{
			if (rst == NULL)
			{
				rst = new ListNode((l1->val + l2->val + carry) % 10);
				carry = (l1->val + carry) / 10;
				last = rst;
			}
			else
			{
				p = new ListNode((l1->val + carry) % 10);
				carry = (l1->val  + carry) / 10;
				last->next = p;
				last = p;
			}
			l1 = l1->next;
		}
		while (l2 != NULL)
		{
			if (rst == NULL)
			{
				rst = new ListNode((l2->val + carry) % 10);
				carry = (l2->val + carry) / 10;
				last = rst;
			}
			else
			{
				p = new ListNode((l2->val + carry) % 10);
				carry = (l2->val + carry) / 10;
				last->next = p;
				last = p;
			}
			l2 = l2->next;
		}
		while (carry)
		{
			if (rst == NULL)
			{
				rst = new ListNode(carry % 10);
				carry = carry / 10;
				last = rst;
			}
			else
			{
				p = new ListNode( carry % 10);
				carry =  carry / 10;
				last->next = p;
				last = p;
			}
		}
		return rst;
	}
};

int main()
{
	ListNode l1(5), l2(4), l3(3), r1(5), r2(6), r3(4);
	l1.next = NULL;
	l2.next = &l3;
	l3.next = NULL;

	r1.next = NULL;
	r2.next = &r3;
	r3.next = NULL;
	Solution s;
	s.addTwoNumbers(&l1, &r1);
	return 0;
}