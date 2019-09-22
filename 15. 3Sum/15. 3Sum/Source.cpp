#include <vector>
#include <map>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector< vector<int> > rst;
		map<int, int> negative,possitive,all;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] <= 0)
			{
				negative[nums[i]] += 1;
			}
			else
			{
				possitive[nums[i]] += 1;
			}
			all[nums[i]] += 1;
		}
		if (negative[0] >= 3)
		{
			rst.push_back({ 0, 0, 0 });
		}
		map<int, int>::iterator nit;
		map<int, int>::reverse_iterator pit;
		for (nit = negative.begin(); nit != negative.end() && negative[nit->first]; nit++)
		{
			all[nit->first] -= 1;
			for (pit = possitive.rbegin(); pit != possitive.rend(); pit++)
			{
				all [pit->first] -= 1;
				int third = 0 -  pit->first - nit->first;

				if (third >= -pit->first && third <= -nit->first &&third>=nit->first && third<=pit->first&&all[third])
				{
					rst.push_back({ nit->first, pit->first, third});
					if (third == 0)
					{
						negative[third] = 0;
					}
				}
				all[pit->first] += 1;
			}
			all[nit->first] += 1;
		}

		return rst;
	}
};

int main()
{
	Solution sol;
	vector< vector<int> > nums = { {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6}, { 3, 0, -2, -1, 1, 2 }, { -1, 0, 1, 2, -1, -4 }
};
	auto rst = sol.threeSum(nums[0]);
	system("pause");
	return 0;
}