#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.size() == 0) return;
		k = k % nums.size();
		int n = nums.size();

		reverse(nums.begin(), nums.end());
		auto it = nums.begin();
		for (int i = 0; i < k; i++)
		{
			it++;
		}

		reverse(nums.begin(), it);
		reverse(it, nums.end());
	}
};
int main()
{
	Solution sol;
	vector<int> nums = { 1,2,3,4,5,6,7 };
	sol.rotate(nums, 3);
	for (auto each : nums) {
		printf("%d", each);
	}
	system("pause");
	return 0;
}