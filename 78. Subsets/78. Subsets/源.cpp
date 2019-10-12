#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <set>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector <vector <int >> rst;
		int n = nums.size();
		int maxn = int(pow(2, n));
		for (int i = 0; i < maxn; i++)
		{
			vector<int> tmp;
			for (int j = 0; j < n; j++)
			{
				if ((i >> j) & 1)
				{
					tmp.push_back(nums[j]);
				}
			}
			rst.push_back(tmp);
		}
		return rst;
	}
};

int main()
{
	Solution sol;
	vector<int > nums = { 1,2,3 };
	auto rst = sol.subsets(nums);
	printf("%d\n", rst.size());
	system("pause");
	return 0;
}