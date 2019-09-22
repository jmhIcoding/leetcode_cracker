#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		
		vector <ListNode *> node_p;
		ListNode * tmp = head;
		while (tmp)
		{
			node_p.push_back(tmp);
			tmp = tmp->next;
		}
		for (int i = 0; i < node_p.size(); i++)
		{
			if (i % 2 == 1)
			{
				if ((i - 2) >= 0)
				{
					node_p[i - 3]->next = node_p[i];
				}
				else
				{
					head = node_p[i];
				}

				node_p[i]->next = node_p[i - 1];

				if ((i+1) < node_p.size())
				{

					node_p[i - 1]->next = node_p[i + 1];
				}
				else
				{
					node_p[i - 1]->next = NULL;
				}
			}
		}
		return head;
	}
};
int main()
{
	Solution sol;
	ListNode n1(1), n2(2), n3(3), n4(4);
	n1.next = &n2;
	//n2.next = &n3;
	//n3.next = &n4;
	ListNode * head = sol.swapPairs(&n1);
	while (head)
	{
		printf("%d->", head->val);
		head = head->next;
	}
	system("pause");
	return 0;
}