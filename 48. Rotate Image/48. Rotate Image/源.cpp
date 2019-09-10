#include <vector>
#include <stdio.h>
using namespace std;
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		//对角线对称
		int n = matrix.size();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < (n - i); j++)
			{
				swap(matrix[i][j], matrix[n -1 - j][n-1 - i]);
			}
		}
		//上下对称
		for (int i = 0; i < (n / 2); i++)
		{
			swap(matrix[i], matrix[n - 1 - i]);
		}
	}
};
int main()
{
	Solution sol;
	vector<vector<int>> matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	sol.rotate(matrix);
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}