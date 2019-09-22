#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int left = 0, right = numbers.size() - 1,n=numbers.size()-1;
		vector<int> rst;
		int sum = 0,last_right=0,last_left=0;
		while (left<right)
		{
			sum = numbers[left] + numbers[right];
			if (sum < target)
			{
				 last_left = numbers[left];
				while (left<n && numbers[left]==last_left)
				{
					left += 1;
				}

			}
			else if (sum>target)
			{
				 last_right = numbers[right];
				while (right>=0 &&numbers[right]==last_right)
				{
					right--;
				}
			}
			else
			{
				rst.push_back(left + 1);
				rst.push_back(right + 1);
				break;
			}
		}
		return rst;
	}
};
int main()
{
	Solution sol;
	vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;
	auto rst = sol.twoSum(nums, target);
	printf("%d,%d", rst[0], rst[1]);
	system("pause");
	return 0;
}