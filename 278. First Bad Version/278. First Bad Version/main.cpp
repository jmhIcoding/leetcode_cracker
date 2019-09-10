#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
bool isBadVersion(int version)
{
	const int first = 4;
	return version >= 4;
}

class Solution {
public:
	int firstBadVersion(int n) {
		int l = 0, r = n,mid;
		while (l<r)
		{
			 mid= (l + r+0LL) / 2;
			if (isBadVersion(mid))
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		return l;
	}
};
int main()
{
	Solution sol;
	printf("%d\n", sol.firstBadVersion(3));
	system("pause");
	return 0;
}