#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> backTrace(vector<int>& candidates, int target,vector<int>& r,int lastNum) {
		vector<vector<int> > rst;
		if (target == 0)
		{
			rst.push_back(r);
			return rst;
		}
		if (target < 0)
		{
			return rst;
		}
		for (int i = 0; i < candidates.size(); i++)
		{
			
			if ((target - candidates[i]) >= 0 && candidates[i] >=lastNum)
			{
				r.push_back(candidates[i]);
				auto subrst =backTrace(candidates, target - candidates[i], r,candidates[i]);
				r.pop_back();
				for (auto each : subrst)
				{
					rst.push_back(each);
				}
			}

		}
		return rst;
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> rst;
		vector<int> tmp;
		rst = backTrace(candidates, target, tmp,1);
		return rst;
	}
};
int main()
{
	Solution sol;
	vector<int> nums = { 1,2,3,4,5,6,7};
	auto rst = sol.combinationSum(nums, 7);
	printf("%d\n", rst.size());
	system("pause");
	return 0;
}