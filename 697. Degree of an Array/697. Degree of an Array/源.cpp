#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	struct _count_struct
	{
		int count;
		int start;
		int end;
	};
	int findShortestSubArray(vector<int>& nums) {
		_count_struct count[5005] = { 0 };

		int max_count = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (count[nums[i]].count == 0)
			{
				count[nums[i]].start = i;
			}
			count[nums[i]].count += 1;
			count[nums[i]].end = i;
			if (count[nums[i]].count > max_count)
			{
				max_count = count[nums[i]].count;
			}

		}
		int min_len = nums.size();
		for (int i =0;i<5001;i++)
		{
			if (count[i].count == max_count)
			{
				if ((count[i].end - count[i].start +1) < min_len)
				{
					min_len = (count[i].end - count[i].start + 1);
					if (min_len == max_count)
					{
						break;
					}
				}
			}
		}
		return min_len;
	}
};
int main()
{
	Solution sol;
	vector<int> nums;
	for (int i = 0; i < 5000; i++) nums.push_back(i);
	printf("%d\n", sol.findShortestSubArray(nums));
	system("pause");
	return 0;
}