#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

class Solution {
#define SUB 2
public:

	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		int sub = 0;
		int cnt = 0;
		for (int i = 0; i < len; i++)
		{
			if (i == 0)
			{
				cnt = 1;
			}
			else if(nums[i]==nums[i-1])
			{
				cnt += 1;
			}
			else
			{
				if (cnt > SUB)
				{
					sub += cnt - SUB;
					for(int j =(i-1);(i-j)<=(cnt-SUB);j--)
					{
						nums[j] = INT_MAX;
					}
				}
				cnt = 1;
			}
		}
		if (cnt > SUB)
		{
			sub += cnt - SUB;
			for (int j = (len - 1); (len - j) <= (cnt - SUB); j--)
			{
				nums[j] = INT_MAX;
			}
		}
		sort(nums.begin(), nums.end());
		return len-sub;
	}
};
int main()
{
	Solution sol;
	vector<int> nums = { 0,0,1,1,1,1,2,3,3 };
	int l=sol.removeDuplicates(nums);
	for(int i =0;i<l;i++)
	printf("%d\t", nums[i]);
	system("pause");
	return 0;
}