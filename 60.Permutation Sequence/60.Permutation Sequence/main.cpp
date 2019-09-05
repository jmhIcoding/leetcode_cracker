#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string>
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
			sort(nums.begin(), nums.end());
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
	vector<int> permuteUnique(vector<int>& nums,int k) {
		sort(nums.begin(), nums.end());
		int cnt = 1;
		while (nextPermute(nums) == true)
		{
			cnt++;
			if (cnt == k)
			{
				break;
			}
		}
		return nums;
	}
	string getPermutation(int n, int k)
	{
		vector<int> nums;
		for (int i = 1; i <= n; i++)
		{
			nums.push_back(i);
		}
		auto permutate = permuteUnique(nums, k);
		string rst;
		for (int i = 0; i < permutate.size(); i++)
		{
			rst.append(1,'0' + permutate[i]);
		}
		return rst;
	}
};
int main()
{
	Solution sol;
	printf("%s\n", sol.getPermutation(3, 1).c_str());
	system("pause");
	return 0;
}