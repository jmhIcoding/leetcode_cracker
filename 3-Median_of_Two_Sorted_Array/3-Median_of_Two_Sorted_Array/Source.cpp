#include <vector>
#include <stdlib.h>
using namespace std;
class Solution {
public:
	void find(vector<int>&nums1, int &s1, int& e1, vector<int> & nums2, int& s2, int & e2)
	{

	}
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		double rst = 0;
		int m = nums1.size();
		int n = nums2.size();
		bool even = (m + n) % 2;//Ææ/Å¼

		return rst;
	}
};

int main()
{
	vector<int> nums1 = { 1, 3 }, nums2 = { 2 };
	Solution s;
	printf("%0.3lf\n", s.findMedianSortedArrays(nums1, nums2));
	return 0;
}