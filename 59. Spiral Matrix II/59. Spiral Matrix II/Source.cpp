#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector <  vector < int >> rst;
		for (int i = 0; i < n; i++)
		{
			rst.push_back({});
			for (int j = 0; j < n; j++)
			{
				rst[i].push_back({});
			}
		}
		int x = 0, y = 0;
		int left = 0, right = n - 1, top = 0, bottom = n - 1;
		int direct = 0;
		for (int i = 0; i < n*n; )
		{	
			if (direct == 0)
			{
				for (int j = left; j <= right; j++)
				{
					rst[x][j] = i + 1;
					i++;
				}
				top++;
				y = right;
			}
			else if (direct == 1)
			{
				for (int j = top; j <= bottom; j++)
				{
					rst[j][y] = i + 1;
					i++;
				}
				right--;
				x = bottom;
			}
			else if (direct ==2)
			{
				for (int j = right; j >= left; j--)
				{
					rst[x][j] = i + 1;
					i++;
				}
				bottom--;
				y = left;

			}
			else if (direct==3)
			{
				for (int j = bottom; j >= top; j--)
				{
					rst[j][y] = i + 1;
					i++;
				}
				left++;
				x = top;
			}
			direct = (direct+1) % 4;
		}
		return rst;

	}
};
int main()
{
	Solution sol;
	auto rst = sol.generateMatrix(3);
	for (int i = 0; i < rst.size(); i++)
	{
		for (int j = 0; j < rst[i].size(); j++)
		{
			printf("%d ", rst[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}