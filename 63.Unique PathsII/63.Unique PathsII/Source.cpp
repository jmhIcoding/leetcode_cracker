#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		long long int paths[101][101] = { 0 };
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		paths[0][0] = 1 - obstacleGrid[0][0];
		for (int i = 1; i < m; i++)
		{
			paths[i][0] = paths[i-1][0] * (1 - obstacleGrid[i][0]);
		}
		for (int j = 1; j < n; j++)
		{
			paths[0][j] = paths[0][j-1] * (1 - obstacleGrid[0][j]);
		}
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				paths[i][j] = (paths[i - 1][j] + paths[i][j - 1])*(1-obstacleGrid[i][j]);
			}
		}
		return paths[m - 1][n - 1];
	}
};

int main()
{
	Solution sol;
	vector<vector<int> > map = { { 1, 0 } };
	printf("%d\n", sol.uniquePathsWithObstacles(map));
	system("pause");
	return 0;
}