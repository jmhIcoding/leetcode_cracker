#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.size() <= 0) return;
		set<int> rows, cols;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				if (matrix[i][j] == 0 )
				{
					rows.insert(i);
					cols.insert(j);

				}
			}
		}
		for (auto i : rows)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				matrix[i][j] = 0;
			}
		}
		for (auto j : cols)
		{
			for (int i= 0; i < matrix.size(); i++)
			{
				
				matrix[i][j] = 0;
			}
		}
	}
};
int main()
{
	Solution sol;
	vector <vector<int> >m = { {0,1} };
	sol.setZeroes(m);
	for (int i =0;i< m.size(); i++)
	{
		for (int j=0;j< m[i].size(); j++)
		{
			printf("%d\t", m[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
