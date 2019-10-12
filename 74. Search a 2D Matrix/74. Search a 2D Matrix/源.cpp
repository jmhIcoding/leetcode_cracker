#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		//二分,首先二分在哪一行
		
		int m = matrix.size(), n = matrix[0].size();
		if (matrix.size()*matrix[0].size() == 0) return false;
		int rs = 0, re =m;
		while (rs<re)
		{
			int mid = (rs + re) / 2;
			if (matrix[mid][n-1] == target)
			{
				return true;
			}
			else if(matrix[mid][n-1]<target)
			{
				rs = mid + 1;
			}
			else 
			{
				if (matrix[mid][0] > target)
				{
					re = mid;
				}
				else if (matrix[mid][0] == target)
				{
					return true;
				}
				else
				{
					rs = mid;
					re = mid;
				}
				
			}
		}
		if(rs >=m) return false;
		if (rs == re)
		{
			int start = 0, end = n;
			while (start<end)
			{
				int mid = (start + end) / 2;
				if (matrix[rs][mid] == target)
				{
					return true;
				}
				else if(matrix[rs][mid]<target)
				{
					start = mid + 1;
				}
				else
				{
					end = mid;
				}
			}
			if (matrix[rs][start] == target)
			{
				return true;
			}
			return false;
		}
		
	}
};
int main()
{
	Solution sol;
	vector<vector<int >> matrix = {  };// { {1, 3, 5, 7}, { 10,11,16,20 }, { 23,30,34,50 } };
	printf("%d\n", sol.searchMatrix(matrix, 100));
	printf("%d\n", sol.searchMatrix(matrix, 13));
	system("pause");
	return 0;
}