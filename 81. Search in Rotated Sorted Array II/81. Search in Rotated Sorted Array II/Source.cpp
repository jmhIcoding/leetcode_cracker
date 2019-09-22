#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool bisearch(vector<int> & nums, int target, int l, int r)
	{
		if (l > r)
		{
			return false;
		}
		else
		{
			if (r==l) return nums[l] == target;
			int mid = (l + r) / 2;
			if (nums[mid] == target)
			{
				return true;
			}
			else
			{
				if (nums[l] < nums[r])
					//µ¥µ÷µÄ
				{
					while (l<=r)
					{
						mid = (l + r) / 2;
						if (nums[mid] < target)
						{
							l = mid + 1;
						}
						else if (nums[mid]>target)
						{
							r = mid-1;
						}
						else
						{
							return true;
						}
					}
					return false;
				}
				else
				{
					return bisearch(nums, target, l, mid-1) || bisearch(nums, target, mid+1, r);
				}

			}
		}
	}
	bool search(vector<int>& nums, int target) {
		if (nums.size() == 0) return false;
		if (nums.size() == 1) return nums[0] == target;
		return bisearch(nums, target, 0, nums.size()-1);
	}
};
int main()
{
	Solution sol;
	vector< vector<int> >nums = { { 1, 1, 1,1,1,1,3,1,1,1,1,1,1,1 }, { 2, 5, 6, 0, 0, 1, 2 }, { 1,3 }, { 3 }, { 3, 3, 3, 3 } };
	vector<int> target = { 3, 3, 3, 3 ,3};
	for (int i = 0; i < target.size(); i++)
	{
		printf("%d\n", sol.search(nums[i], target[i]));
	}
	system("pause");
	return 0;
}