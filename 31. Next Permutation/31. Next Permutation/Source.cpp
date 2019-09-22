#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int n = nums.size();
		if (n <= 1)
		{
			return;
		}
		int change = 1;
		vector<int> ::iterator it = nums.begin(),cit=nums.begin()+1;
		int index = change;
		int minx = nums[index];
		for (int i = 1; i <n; i++)
		{
			if (nums[i]>nums[i - 1])
			{
				index=change = i;
				it = cit;
				minx = nums[index];
			}
			if (nums[i] > nums[change - 1] && nums[i] < minx)
			{
				minx = nums[i];
				index = i;
			}
			cit++;
		}
		if (change == 0)
			//已经是最大的了
		{
			int left = 0, right = n - 1;
			while (left<right)
			{
				int tmp = nums[left];
				nums[left] = nums[right];
				nums[right] = tmp;
				left++;
				right--;
			}
		}
		else
		{
			change -= 1;
			int tmp = nums[change];
			nums[change] = nums[index];
			nums[index] = tmp;
			//change后面 排序
			sort(it, nums.end());
		}
	}
};
int main()
{
	Solution sol;
	vector <vector<int>> tests = { { 1, 3,2 }, { 3, 2, 1 }, { 1, 1, 5 } };
	for (auto test : tests)
	{
		sol.nextPermutation(test);
		for (int i = 0; i < test.size(); i++)
		{
			printf("%d -", test[i]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}