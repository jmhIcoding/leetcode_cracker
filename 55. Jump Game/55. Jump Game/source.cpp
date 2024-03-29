#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int maxn = nums[0];
		int i = 0;

		while (i<n)
		{
			int l = min(maxn,n-1);
			for (int j = i; j <= l; j++)
			{
				if (maxn < (j + nums[j]))
				{
					maxn = j + nums[j];
					if (maxn >= (n - 1)) return true;
				}
			}
			if (l == i) break;
			i += (l - i);
			
		}
		return maxn >= (n - 1);
	}
};
int main()
{
	vector<int> nums = {2,3,1,1,4};
	Solution sol;
	printf("%d\n", sol.canJump(nums));
	system("pause");
	return 0;
}
