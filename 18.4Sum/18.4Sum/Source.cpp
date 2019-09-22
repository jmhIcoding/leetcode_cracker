#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> rst;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			if (nums[i]>0 && nums[i]>target) break;
			for (int j = i + 1; j < n; j++)
			{
				if (nums[j]>0 &&(nums[i]+nums[j])>target) break;
				int left = j + 1, right = n - 1;
				while (left < right)
				{
					int sum = nums[i] + nums[j] + nums[left] + nums[right];
					if (sum < target)
					{
						int last_left = nums[left];
						while (left<n &&left<right&& (nums[left] == last_left))
						{
							left += 1;
						}
					}
					else if (sum > target)
					{
						int last_right = nums[right];
						while (right>=0 && left <right&&(nums[right] == last_right))
						{
							right--;
						}
					}
					else
					{
						rst.push_back({nums[i],nums[j],nums[left],nums[right]});
						int last_left = nums[left], last_right = nums[right];
						while ((left) < n &&left < right && (last_left == nums[left]))
						{
							left += 1;
						}
						while (right >= 0 && left < right && (last_right == nums[right]))
						{
							right -= 1;
						}
					}
				}
				while ((j+1)<n && nums[j+1]==nums[j])
				{
					j++;
				}
			}
			while ((i + 1)<n && nums[i + 1] == nums[i])
			{
				i++;
			}
		}

		return rst;
	}
};
int main()
{
	Solution sol;
	vector<int> nums = { -1, 0, -5, -2, -2, -4, 0, 1, -2};
	printf("%d\n", sol.fourSum(nums, -9).size());
	system("pause");
	return 0;
}