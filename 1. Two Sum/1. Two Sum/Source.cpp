#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	struct _bind
	{
		int val;
		int index;
		bool operator<(const _bind &rh) const
		{
			return val < rh.val;
		}
	};
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> rst;
		vector<_bind> bind;
		for (int i = 0; i < nums.size(); i++)
		{
			bind.push_back({ nums[i], i });
		}
		sort(bind.begin(), bind.end());
		int left = 0, right = nums.size()-1;
		while (left<right)
		{
			int sum = bind[left].val + bind[right].val;
			if (sum < target)
			{
				left++;
			}
			else if (sum>target)
			{
				right--;
			}
			else if (sum == target)
			{
				rst.push_back(bind[left].index);
				rst.push_back(bind[right].index);
				break;
			}
		}
		return rst;
	}
};
int main()
{
	Solution sol;
	vector<int> nums = { 3,2,4};
	auto rst = sol.twoSum(nums, 6);
	printf("%d,%d\n", rst[0], rst[1]);
	system("pause");
	return 0;
}