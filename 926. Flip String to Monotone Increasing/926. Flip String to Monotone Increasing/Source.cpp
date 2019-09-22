#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//前缀数组 计算出各个前缀中含1的个数
//枚举答案
class Solution {
public:
	int minFlipsMonoIncr(string S) {
		vector<int> psum;
		int n = S.size();
		psum.push_back(0);
		for (int i = 0; i < S.size(); i++)
		{
			if (i == 0)
			{
				psum.push_back(S[i] == '1');
			}
			else
			{
				psum.push_back(psum[i] + (S[i] == '1'));
			}
		}
		int ans = S.size();
		for (int i = 0; i <= S.size(); i++)
		{
			ans = min(ans, psum[i] + (n - i) - (psum[n] - psum[i]));
			
		}
		return ans;
	}
};
int main()
{
	Solution sol;
	printf("%d\n", sol.minFlipsMonoIncr("11011"));
	
	system("pause");
	return 0;
}