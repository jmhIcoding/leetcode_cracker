#include <stdio.h>
#include <stdlib.h>
class Solution {
public:
	int mySqrt(int x) {
		if (x <= 1) return x;
		if (x < 4) return 1;
		if (x == 4) return 2;
		int start = 0;
		int end = x/2;
		while (start<end)
		{
			int mid = (start + end) / 2;
			if (mid * mid < x)
			{
				start = mid+1;
			}
			else if (mid *mid>x)
			{
				end = mid;
			}
			else
			{
				return mid;
			}
		}
		return start-1;
	}
};
int main()
{
	Solution sol;
	printf("%d\n", sol.mySqrt(9));
	system("pause");
	return 0;
}