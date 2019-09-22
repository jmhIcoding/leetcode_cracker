#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
class Solution {
public:
	int findKthNumber(int m, int n, int k) {
		int count = 1;
		int i = 2;
		for (; i <= min(m, n); i++)
		{
			count += 2;
		}
	}
};
int main()
{
	Solution sol;
	printf("%d\n", sol.findKthNumber(3, 3, 5));
	return 0;
}