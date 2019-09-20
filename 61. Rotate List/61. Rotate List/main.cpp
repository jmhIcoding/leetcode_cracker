#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k)
	{
		
		int n = 0;
		ListNode * p = head;
		vector<ListNode *> points;
		while (p)
		{
			points.push_back(p);
			p = p->next;
			n++;
		}
		if (n == 0)
		{
			return head;
		}
		k = k % n;
		if (k != 0)
		{
			points[n- k- 1]->next = NULL;
			points[n - 1]->next = points[0];
		}
		else
		{
			return head;
		}
		return points[n-k];
	}
};
int main()
{
	Solution sol;
	ListNode n0(0), n1(1), n2(2);
	//n0.next = &n1;
	//n1.next = &n2;
	n2.next = NULL;
	ListNode * p = sol.rotateRight(&n0, 1);

	while (p)
	{
		printf("%d->", p->val);
		p = p->next;
	}

	system("pause");
	return 0;
}