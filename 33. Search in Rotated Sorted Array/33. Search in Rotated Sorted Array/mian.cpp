#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class Solution {
public:
	int binary_search(vector<int> & nums, int l, int r,int target)
	{
		int rst = -1;
		while (l<r)
		{
			int mid = (l + r) / 2;
			if (nums[mid] < target)
			{
				l = mid+1;
			}
			else if(nums[mid]>target)
			{
				r = mid;
			}
			else
			{
				return mid;
			}
		}
		if (nums[l] == target)
		{
			return l;
		}
		if (nums[r] == target)
		{
			return r;
		}
		return rst;
	}
	int search(vector<int>& nums, int target) {
		int rst = -1;
		int split = 0;
		int l, r, n;
		l = 1, r = nums.size(), n = nums.size() - 1;
		if (n == 0)
		{
			if (nums[0] == target) return 0;
			else
			{
				return -1;
			}
		}
		if (n < 0)
		{
			return -1;
		}
		while (l < r)
		{
			int mid = (l + r) / 2;
			if (nums[mid] > nums[0])
			{
				l = mid + 1;
			}
			else if (nums[mid] < nums[0])
			{
				r = mid;
			}
		}
		split = l;
		if (split<=n && target < nums[split])
		{
			return -1;
		}
		if (split>0 && target > nums[split - 1])
		{
			return -1;
		}
		if (split <=n && target >= nums[split] && target <= nums[n])
		{
			rst = binary_search(nums, split, n + 1,target);
		}
		else
		{
			rst = binary_search(nums, 0, split,target);
		}
		return rst;
	}
};
int main()
{
	vector<int> nums = {1,3};
	Solution sol;
	printf("%d", sol.search(nums, 0));
	system("pause");
	return 0;
}