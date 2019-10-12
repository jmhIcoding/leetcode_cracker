#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
class Solution {
public:
	int jump(vector<int>& nums) {
		int n = nums.size();
		int maxn = nums[0];
		int i = 0;
		int step = 0;
		while (i<n)
		{
			
			int l = min(maxn, n - 1);

			for (int j = i; j <= l; j++)
			{
				if (maxn < (j + nums[j]))
				{
					maxn = j + nums[j];
					if (maxn >= (n - 1)) break;
				}
			}
			if (l == i) break;
			step += 1;
			i += (l - i);
		}
		return step;
	}
};
int main()
{
	vector<int> nums = { 1,2,3 };
	Solution sol;
	printf("%d\n", sol.jump(nums));
	system("pause");
	return 0;
}
