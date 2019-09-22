#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
//回溯的题目,有剪枝
class Solution {
public:
	bool isValid(int x, int y, vector<vector<int>> & grid, vector<vector<int>> & paths, int m, int n)
	{
		if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y]==-1 || paths[x][y]==1)
		{
			return false;
		}
		return true;
	}
	int backtrace(vector<vector<int> > & grid, vector<vector<int>> & paths, int depth,int& m,int& n,int x, int y,int& required)
	{
		int rst = 0;
		if (grid[x][y] == 2)
		{
			if (depth == required)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		if (depth >= required) return 0;
		for (int i = 0; i < 4; i++)
		{
			switch (i)
			{
			case 0:
				if (isValid(x + 1, y, grid, paths, m, n))
				{
					paths[x + 1][y] = 1;
					rst += backtrace(grid, paths, depth+1, m, n, x + 1, y,required);
					paths[x + 1][y] = 0;
				}
				break;
			case 1:
				if (isValid(x - 1, y, grid, paths, m, n))
				{
					paths[x - 1][y] = 1;
					rst += backtrace(grid, paths, depth+1, m, n, x - 1, y,required);
					paths[x - 1][y] = 0;
				}
				break;
			case 2:
				if (isValid(x, y+1, grid, paths, m, n))
				{
					paths[x][y+1] = 1;
					rst += backtrace(grid, paths, depth+1, m, n, x , y+1,required);
					paths[x ][y+1] = 0;
				}
				break;
			case 3:
				if (isValid(x, y-1, grid, paths, m, n))
				{
					paths[x][y-1] = 1;
					rst += backtrace(grid, paths, depth+1, m, n, x, y-1,required);
					paths[x][y-1] = 0;
				}
				break;
			default:
				break;
			}
		}
		return rst;
	}
	int uniquePathsIII(vector<vector<int>>& grid) {
		int m=grid.size(), n=grid[0].size();
		vector<vector<int>> paths;
		int required = 0;
		int x, y;
		for (int i = 0; i < m; i++)
		{
			paths.push_back({});
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 1)
				{
					x = i, y = j;
				}
				if (grid[i][j] != -1)
				{
					required += 1;
				}
				paths[i].push_back(0);
			}
		}
		paths[x][y] = 1;
		return backtrace(grid, paths, 1, m, n, x, y, required);
	}
};
int main()
{
	Solution sol;
	vector<vector <int >> grid = { { 1, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 2 } };
	printf("%d\n", sol.uniquePathsIII(grid));
	system("pause");
	return 0;
}