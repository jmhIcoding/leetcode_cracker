#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class Solution {
public:
	void split(vector<int> &nums, int l, int r)
	{

	}
	void sortColors(vector<int>& nums) {

	}
};
int main()
{
	Solution sol;
	vector<int > nums = { 2,0,2,1,1,0 };
	sol.sortColors(nums);
	for (int i = 0; i < nums.size(); i++) printf("%d\t", nums[i]);
	system("pause");
	return 0;
}