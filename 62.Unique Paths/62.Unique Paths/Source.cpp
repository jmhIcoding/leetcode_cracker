#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
class Solution {
public:
	int uniquePaths(int m, int n) {
		int paths[101][101] = { 0 };
		for (int i = 0; i < m; i++)
		{
			paths[i][0] = 1;
		}
		for (int j = 0; j < n; j++)
		{
			paths[0][j] = 1;
		}
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
			}
		}
		return paths[m - 1][n - 1];
	}
};

int main()
{
	Solution sol;
	printf("%d\n", sol.uniquePaths(3, 3));
	system("pause");
	return 0;
}