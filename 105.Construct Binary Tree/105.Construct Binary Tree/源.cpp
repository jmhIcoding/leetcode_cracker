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
	TreeNode * build(vector<int> & preorder, vector<int> &inorder, int pl, int pr,int il,int ir)
	{
		if (pl >= pr)
		{
			return NULL;
		}
		if (il >= ir)
		{
			return NULL;
		}
		int i;
		TreeNode * node=NULL;
		for (i = il; i < ir; i++)
		{
			if (preorder[pl] == inorder[i])
			{
				node = new TreeNode(preorder[pl]);
				//找到了Head
				break;
			}
		}
		if (node == NULL) return NULL;
		//处理左边
		TreeNode * left = build(preorder, inorder, pl + 1, pl + i-il +1 , il, i);
		//处理右边
		TreeNode * right = build(preorder, inorder, pl + i-il +1,pr,i+1 ,ir );
		node->left = left;
		node->right = right;
		return node;

	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
	{
		return build(preorder, inorder, 0, preorder.size(), 0, inorder.size());
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
	vector<int> preorder = { 3, 9, 20, 15, 7 };
	vector<int> inorder = {9, 3, 15, 20, 7};
	Solution sol;
	TreeNode * head = sol.buildTree(preorder, inorder);
	sol.traver(head);
	system("pause");
	return 0;
}