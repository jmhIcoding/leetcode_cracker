#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool nextPermute(vector<int> & nums)
	{
		int n = nums.size();
		int change = 0;
		for (int i = 1; i < n; i++)
		{
			if (nums[i] > nums[i - 1])
			{
				change = i;
			}
		}
		if (change == 0)
		{
			return false;
		}
		else
		{
			change--;
			int minx = nums[change + 1];
			int index = change + 1;
			for (int j = change + 1; j < n; j++)
			{
				if (nums[j] > nums[change] && nums[j] < minx)
				{
					index = j;
					minx = nums[j];
				}
			}
			swap(nums[change], nums[index]);
			vector<int>::iterator it = nums.begin();
			change++;
			for (int i = 0; i < n; i++)
			{
				if (i == change)
				{
					break;
				}
				it++;
			}
			sort(it, nums.end());
			return true;
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector <int> > rst;
		rst.push_back(nums);
		while (nextPermute(nums)==true)
		{
			rst.push_back(nums);
		}
		return rst;
	}
};
int main()
{
	Solution sol;
	vector<int> tests = { 1,2,3 };
	auto rst = sol.permuteUnique(tests);
	for (auto item : rst)
	{
		for (int i = 0; i < item.size(); i++)
		{
			printf("%d ", item[i]);

		}
		printf("\n\n");
	}
	system("pause");
	return 0;
}