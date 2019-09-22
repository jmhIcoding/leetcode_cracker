#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int rst = INT_MAX;
		int closet = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			//if (nums[i]>target) break;
			if (rst == target) break;
			int left = i + 1, right = n - 1;
			while (left < right)
			{
				int sum = nums[i] + nums[left] + nums[right];
				if (sum < target)
				{
					if ((target - sum) < closet)
					{
						closet = target - sum;
						rst = sum;
					}
					if ((left + 1) < n && nums[left] == nums[left + 1])
					{
						while ((left + 1)<n && nums[left] == nums[left + 1])
						{
							left++;
						}
					}
					else
						left += 1;
				}
				else if (sum >target)
				{
					if ((sum - target) < closet)
					{
						closet = sum - target;
						rst = sum;
					}
					if ((right - 1) >= 0 && nums[right] == nums[right - 1])
					{
						while ((right - 1) >= 0 && nums[right] == nums[right - 1])
						{
							right--;
						}
					}
					else
						right -= 1;
				}
				else
				{
					return target;
				}
			}
		}
		return rst;
	}
};
int main()
{
	Solution sol;
	vector<int> nums = { 0,2,1,-3};
	int target = 1;
	printf("%d\n", sol.threeSumClosest(nums, target));
	system("pause");
	return 0;
}