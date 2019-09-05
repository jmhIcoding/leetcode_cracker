#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class Solution {
public:
	int findMin(vector<int>& nums) {
		int rst = -1;
		int split = 0;
		int l, r, n;
		l = 1, r = nums.size(), n = nums.size() - 1;
		while (l < r)
		{
			int mid = (l + r) / 2;
			if (nums[mid] >= nums[0])
			{
				l = mid + 1;
			}
			else if (nums[mid] < nums[0])
			{
				r = mid;
			}
		}
		split = l;
		if (split <= n)
		{
			return nums[split];
		}
		else
		{
			return nums[0];
		}
	}
};
int main()
{
	vector<int> nums = { 1,2,3,4 ,0};
	Solution sol;
	printf("%d", sol.findMin(nums));
	system("pause");
	return 0;
}