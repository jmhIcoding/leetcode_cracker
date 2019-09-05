#include <vector>
#include<algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Solution {
public:
	int binary_search(vector<int> &nums, int target)
	{
		int rst = -1;
		int l = 0, r = nums.size();
		while (l<r)
		{
			int mid = (l + r) / 2;
			if (nums[mid] < target)
			{
				l = mid + 1;
			}
			else
			{
				r = mid;
			}
		}
		if ((l + 1) <= nums.size() && nums[l] == target)
		{
			return l;
		}
		if ((r + 1) <= nums.size() && nums[r] == target)
		{
			return r;
		}
		return rst;
	}
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> rst = { -1,-1 };
		int index = binary_search(nums, target);
		if (index == -1)
		{
			return rst;
		}
		rst[0] = index;
		rst[1] = index;
		for(int i =index;i<nums.size() && nums[i]==nums[index];i++)
		{
			rst[1] = i;
		}
		return rst;

	}
};
int main()
{
	Solution sol;
	vector<int> nums = { 1 };
	auto rst = sol.searchRange(nums, 1);
	printf("[%d,%d]\n", rst[0], rst[1]);
	system("pause");
	return 0;
}