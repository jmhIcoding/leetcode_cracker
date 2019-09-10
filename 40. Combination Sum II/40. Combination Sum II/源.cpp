#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> backTrace(vector<int> &nums, int target, int lastIndex, vector<int> & r)
	{
		vector< vector<int>> rst;
		if (target == 0)
		{
			rst.push_back(r);
			return rst;
		}
		else if(target< 0)
		{
			return rst;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if ((target - nums[i]) >= 0 && i > lastIndex)
			{
				r.push_back(nums[i]);
				auto subrst = backTrace(nums, target - nums[i], i, r);
				r.pop_back();
				for (auto each : subrst)
				{
					rst.push_back(each);
				}
				int last = nums[i];
				while (i < nums.size() && last == nums[i])
				{
					i++;
				}
				if (i<nums.size() && nums[i] != last)
				{
					i--;
				}
			}

		}
		return rst;
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
	{
		sort(candidates.begin(), candidates.end());
		vector<vector<int> > rst;
		vector<int > tmp;
		rst = backTrace(candidates, target, -1, tmp);
		return rst;

	}
};

int main()
{
	Solution sol;
	vector<int> candidates = {2,5,2,1,2};
	int target = 5;
	auto rst = sol.combinationSum2(candidates, target);
	printf("%d->\n", rst.size());
	system("pause");
	return 0;
}