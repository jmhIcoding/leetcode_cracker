#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.size() == 0) return 0;
		vector <int> dp;
		int i = 0, j = 0;
		for (i = 0; i < grid[0].size(); i++)
		{
			dp.push_back(0);
			if (i == 0)
			{
				dp[i] = grid[0][i];
			}
			else
			{
				dp[i] = dp[i - 1] + grid[0][i];
			}
		}
		
		for (i = 1; i < grid.size(); i++)
		{
			for (j = 0; j < grid[i].size(); j++)
			{
				if (j == 0)
				{
					dp[j] = dp[j] + grid[i][j];
				}
				else
				{
					dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
				}
			}
		}
		return dp[grid[0].size()-1];
	}
};
int main()
{
	Solution sol;
	vector < vector <int> > grid = { {1} };// { {1, 3, 1}, { 1,5,1 }, { 4,2,1 } };
	printf("%d\n", sol.minPathSum(grid));
	system("pause");
	return 0;
}