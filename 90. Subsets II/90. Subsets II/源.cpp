#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		set< vector <int> > rst;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int maxn = pow(2, n);
		for (int i = 0; i < maxn; i++)
		{
			vector<int> tmp;
			for (int j = 0; j < n; j++)
			{
				if (((i >> j) & 1) == 1)
				{
					tmp.push_back(nums[j]);
				}
			}
			rst.insert(tmp);
		}
		vector<vector<int> > out;
		for (auto it : rst)
		{
			out.push_back(it);
		}
		return out;
	}
};
int main()
{
	vector<int> nums = { 4,4,4,1,4};
	Solution sol;
	auto rst = sol.subsetsWithDup(nums);
	for (int i = 0; i < rst.size(); i++)
	{
		for (int j = 0; j < rst[i].size();j++)
		{
			printf("%d ", rst[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}