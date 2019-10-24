/*
������ж�;
һ��ʼû�п�������,��Ϊÿ�����ֿ���ʹ�ö�Ρ�
���淢��ÿ���������ֻ��ʹ��һ�Σ��������һ���Ӽ򵥡�
*/
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
	void backtrace(int k, int n, int index, vector<int> & single,vector<vector<int>>& rst)
	{
		if (index == 0 || n == 0||k==0)
		{
			if (n == 0 && k == 0)
			{
				vector<int > tmp;
				for (int i = 0; i < single.size(); i++)
				{
					int t = single[i]; 
					while (t>0)
					{
						tmp.push_back(9 - i);
						t--;
					}
				}
				rst.push_back(tmp);
			}
		}
		else
		{
			for (int xi = 0; xi <= 1; xi++)
			{
				single.push_back(xi);
				if ((n - index*xi) >= 0)
				{
					backtrace(k - xi, n - index * xi, index-1, single, rst);
				}
				single.pop_back();
			}
		}
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> rst;
		for (int x9 = 0; x9 <= 1; x9++)
		{
			vector<int> single = { x9 };
			if ((n - 9 * x9) >= 0)
			{
				backtrace(k - x9, n - 9 * x9, 8, single, rst);
			}
		}
		return rst;
	}
};
int main()
{
	Solution sol;
	auto rst = sol.combinationSum3(3, 15);
	for (auto each : rst)
	{
		for (int i = 0; i < each.size(); i++)
			printf("%d ", each[i]);
		printf("\n");
	}
	system("pause");
	return 0;
}