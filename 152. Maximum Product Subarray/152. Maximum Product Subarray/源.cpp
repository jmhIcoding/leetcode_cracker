#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int maxp = nums[0],tmp;

		vector<int> product;
		for (int i = 0; i < nums.size(); i++)
		{
			product.push_back(nums[i]);
			if (nums[i] > maxp) maxp = nums[i];
			if (nums[i] == 1) continue;
			for (int j = 0; j < i; j++)
			{
				product[j] *= nums[i];
				if (product[j] > maxp)
				{
					maxp = product[j];
				}
			}
		}
		return maxp;
	}
};
int main()
{
	Solution sol;
	vector<int> nums = { -2,3,-4 };
	printf("%d\n", sol.maxProduct(nums));
	system("pause");
	return 0;
}