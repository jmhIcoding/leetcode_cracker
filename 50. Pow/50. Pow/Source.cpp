#include <algorithm>
#include <math.h>
using namespace std;
class Solution {
public:
	double myPow(double x, int n) {
		
		return pow(x, n);
	}
};

int main()
{
	Solution sol;
	printf("%lf\n", sol.myPow(2, -2));
	system("pause");
	return 0;
}