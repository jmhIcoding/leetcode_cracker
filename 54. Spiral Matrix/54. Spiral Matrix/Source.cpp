#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {

		vector<int> rst;
		int m = matrix.size(), n = 0;// MxN
		if (m > 0)
		{
			n = matrix[0].size();
		}
		int x = 0, y = 0;
		int left = 0, right = n - 1, top = 0, bottom = m - 1;
		int direction = 0;
		while (rst.size()<m*n)
		{
			if (direction == 0)
			{
				for (int i = left; i <= right; i++)
				{
					rst.push_back(matrix[x][i]);
				}
				top++;
				y=right;
			}
			else if (direction == 1)
			{
				for (int i = top; i <= bottom; i++)
				{
					rst.push_back(matrix[i][y]);
				}
				right--;
				x=bottom;
			}
			else  if (direction == 2)
			{
				for (int i = right; i >= left; i--)
				{
					rst.push_back(matrix[x][i]);
				}
				bottom--;
				y=left;
			}
			else if(direction == 3)
			{
				for (int i = bottom; i >= top; i--)
				{
					rst.push_back(matrix[i][y]);
				}
				left++;
				x=top;
			}
			direction = (direction + 1 ) % 4;
		}
		return rst;
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> mat = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	auto rst = sol.spiralOrder(mat);
	for (int i = 0; i < rst.size(); i++)
	{
		printf("%d ", rst[i]);
	}
	system("pause");
	return 0;

}