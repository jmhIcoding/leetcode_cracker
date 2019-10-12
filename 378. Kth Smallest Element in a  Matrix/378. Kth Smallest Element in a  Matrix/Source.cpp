#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int ks(vector<int> &nums, int k,int _l,int _r)
	{
		int l = _l, r = _r;
		int cursor = nums[l];
		while (l<r)
		{
			while (r> l && nums[r]>=cursor)
			{
				r--;
			}
			if (r > l)
			{
				nums[l] = nums[r];
			}
			else
			{
				break;
			}
			while (r>l && nums[l]<=cursor)
			{
				l++;
			}
			if (r > l)
			{
				nums[r] = nums[l];
			}
			else
			{
				break;
			}
		}
		nums[l] = cursor;
		if (l == k)
		{
			return cursor;
		}
		else if(l < k)
		{
				return ks(nums, k, l + 1, _r);
		}
		else
		{
			return ks(nums, k, _l, l-1);
		}
	}
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		vector<int> nums;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				nums.push_back(matrix[i][j]);
			}
		}
		return ks(nums, k - 1, 0, nums.size() - 1);
	}
};
int main()
{
	Solution sol;
	vector<vector<int> > matrix = { { 1, 5, 9 }, { 10, 11, 13 }, { 12, 13, 15 } };
	printf("%d\n", sol.kthSmallest(matrix, 7));
	system("pause");
	return 0;
}