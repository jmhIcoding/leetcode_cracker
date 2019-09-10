#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int rst = 0;
		vector<bool> reach;
		for (int i = 0; i < nums.size(); i++)
		{
			reach.push_back(0);
		}
		reach[0] = 1;
		int lastindex = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if ((i + nums[i]) <= lastindex)
			{
				continue;
			}
			for (int j = max(1, lastindex - nums[i]); j <= nums[i] && (i + j) < nums.size(); j++)
			{
				reach[i + j] = reach[i];
				if ((i + j) > lastindex)
				{
					lastindex = i + j;
				}
				if (reach[nums.size() - 1])
				{
					return true;
				}
			}
		}
		return reach[nums.size() - 1];
	}
};
int main()
{
	Solution sol;
	vector<int> nums = { 1,1,2,2,0,1,1};
	printf("%d\n", sol.canJump(nums));

	system("pause");
	return 0;
}