#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution{
public:
	ListNode *merge2Lists(ListNode *l1, ListNode *l2)
	{
		ListNode * rst=NULL,*head=NULL;

		while (l1!=NULL && l2!=NULL)
		{
			if (l1->val < l2->val)
			{
				ListNode *tmp = l1;
				l1 = l1->next;
				if (rst == NULL)
				{
					rst = tmp;
					head = rst;
					//rst->next = l1;
				}
				else
				{
					
					rst->next = tmp;
					rst = rst->next;
				}
				
			}
			else
			{
				ListNode * tmp = l2;
				l2= l2->next;
				if (rst == NULL)
				{
					rst = tmp;
					head = rst;
				}
				else
				{
					rst->next = tmp;
					rst = rst->next;
				}
			}
			
		}
		while (l1!=NULL)
		{
			ListNode *tmp = l1;
			l1 = l1->next;
			if (rst == NULL)
			{
				rst = tmp;
			}
			else
			{
				rst->next = tmp;
				rst = rst->next;
			}
			
		}
		while (l2!=NULL)
		{
			ListNode *tmp = l2;
			l2 = l2->next;
			if (rst == NULL)
			{
				rst = tmp;
			}
			else
			{
				rst->next = tmp;
				rst = rst->next;
			}

			
		}
		if (rst)
		{
			rst->next = NULL;
		}
		return head;
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		deque<ListNode*> head;
		vector<int> numbers;
		for (int i = 0; i < lists.size(); i++)
		{
			ListNode * tmp = lists[i];
			if (tmp)
				head.push_front(tmp);
		}
		while (head.size()>1)
		{
			//提取出头两个列表进行合并
			ListNode *l1 = head.back();
			head.pop_back();
			ListNode *l2 = head.back();
			head.pop_back();
			ListNode *l = merge2Lists(l1, l2);
			head.push_front(l);
		}
		if (head.size() == 1)
		{
			return head.back();
		}
		else
		{
			return NULL;
		}
	}
};
int main()
{
	Solution sol;
	ListNode a1(1), a2(4), a3(5);
	//a1.next = &a2, a2.next = &a3;
	ListNode b1(1), b2(3), b3(4);
	//b1.next = &b2, b2.next = &b3;
	ListNode c1(2), c2(6);
	c1.next = &c2;
	vector <ListNode *> lists;
	lists.push_back(NULL);
	lists.push_back(NULL);
	lists.push_back(&c1);
	ListNode* head = sol.mergeKLists(lists);
	while (head)
	{
		printf("%d->", head->val);
		head=head->next;
	}
	system("pause");
	return 0;
}