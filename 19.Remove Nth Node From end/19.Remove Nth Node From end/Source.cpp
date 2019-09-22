#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

/**
* Definition for singly-linked list.*/
 struct ListNode {
    int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		vector<ListNode *> node_p;
		ListNode *tmp = head;
		while (tmp)
		{
			node_p.push_back(tmp);
			tmp = tmp->next;
		}
		int len = node_p.size();
		if (n <= 0)
		{
			return head;
		}
		if (n > len)
		{
			return head;
		}
		if (n == 1 && len == 1)
		{
			head->next = NULL;
			head = NULL;
			return head;
		}
		if (n ==1)
		{
			node_p[len - 2]->next = NULL;
			//free(node_p[len - 1]);
			return head;
		}
		else if(n == len)
			//head
		{
			node_p[0]->next = NULL;
			//free(node_p[0]);
			return node_p[1];
		}
		else
		{
			int index = len - n;
			node_p[index - 1]->next = node_p[index]->next;
			//free(node_p[index]);
			return head;
		}

	}
};
int main()
{
	vector<ListNode> nodes;
	nodes.push_back({ 1 });
	nodes.push_back({ 2 });
	nodes.push_back({ 3 });
	nodes.push_back({ 4 });
	nodes.push_back({ 5 });
	nodes[0].next = &nodes[1];
	nodes[1].next = NULL;// &nodes[2];
	nodes[2].next = &nodes[3];
	nodes[3].next = &nodes[4];
	nodes[4].next = NULL;
	Solution sol;
	//n=1,5,4
	ListNode * head = sol.removeNthFromEnd(&nodes[0],2);
	while (head)
	{
		printf("%d->", head->val);
		head = head->next;
	}
	system("pause");
	return 0;
}