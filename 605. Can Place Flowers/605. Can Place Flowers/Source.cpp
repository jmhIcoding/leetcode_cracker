#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int findPlots(vector<int> & flowerbed, int l, int r)
	{
		vector<int > dp;
		int maxn = 0;
		for (int i = l; i <= r; i++)
		{
			dp.push_back(0);
			if (i == l)
			{
				dp[i-l] = (flowerbed[l] == 0);
			}
			else if (i == (1+l))
			{
				if (flowerbed[i - 1])
				{
					dp[i-l] = 0;
				}
				else if (flowerbed[i] == 0)
				{
					dp[i-l] = (max(1, dp[0]));
				}
			}
			else
			{
				if (flowerbed[i - 1])
				{
					dp[i-l] = 0;
				}
				else if (flowerbed[i])
				{
					dp[i-l] = 0;
					dp[i - 1-l] = 0;
				}
				else if (flowerbed[i] == 0)
				{
					int cnt = max(dp[i - 2-l] + 1, dp[i - 1-l]);
					dp[i-l] = cnt;
				}
			}
		}
		for (int i = 0; i < dp.size(); i++)
		{
			if (maxn < dp[i]) maxn = dp[i];
		}
		return maxn;
	}
	bool canPlaceFlowers(vector<int>& flowerbed, int n) 
	{
		flowerbed.insert(flowerbed.begin(), 0);
		flowerbed.insert(flowerbed.begin(), 1);
		vector<int > dp;
		int maxn = 0;
		int last1 = 0;
		for (int i = 1; i < flowerbed.size(); i++)
		{
			if (flowerbed[i] == 1)
			{
				int tmp = findPlots(flowerbed, last1, i);
				maxn += tmp;
				last1 = i;
			}
		}
		if (last1 != (flowerbed.size() - 1))
		{
			flowerbed.push_back(0);
			flowerbed.push_back(1);
			maxn += findPlots(flowerbed, last1, flowerbed.size() - 1);
		}
		return maxn>=n;

	}
};

int main()
{
	Solution sol;
	vector<int> flowers = {1,0,0,0,1,0,0};
	printf("%d\n", sol.canPlaceFlowers(flowers,2));
	system("pause");
	return 0;
}