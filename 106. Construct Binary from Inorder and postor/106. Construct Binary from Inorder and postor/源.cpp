#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode * build(vector<int> & inorder, vector<int> &postorder, int il, int ir, int pl, int pr)
	{
		if (pl > pr) return NULL;
		if (il > ir) return NULL;
		TreeNode * head = NULL;
		int i;
		for ( i =il;i<=ir;i++)
		{
			if (inorder[i] == postorder[pr])
			{
				head = new TreeNode(inorder[i]);
				break;
			}
		}
		if (head == NULL) return NULL;
		TreeNode *right = build(inorder,postorder,i+1,ir,pl+i-il,pr-1);
		TreeNode *left = build(inorder,postorder,il,i-1,pl,pl+i-il -1);
		head->left = left;
		head->right = right;
		return head;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
	}

	void traver(TreeNode * head)
	{
		if (head == NULL)
		{
			return;
		}
		traver(head->left);
		printf("%d\t", head->val);
		traver(head->right);
	}
};
int main()
{
	vector<int>postorder = { 9,15,7,20,3 };
	vector<int> inorder = { 9,3,15,20,7};
	Solution sol;
	TreeNode * head = sol.buildTree( inorder,postorder);
	sol.traver(head);
	system("pause");
	return 0;
}