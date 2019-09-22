#include <string>
#include <stdio.h>
#include <set>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.length();
		int *count =(int*) malloc(sizeof(int)*n);
		//count[i]:��ʾ��s[i]��β��������������Ӵ�����
		set<char> *diff = new set<char>[n];
		int max = 0;
		if (n == 0 || n == 1) return n;
		count[0] = 1;
		diff[0].insert(s[0]);
		for (int i = 1; i < n; i++)
		{
			count[i] = count[i-1];
			for (int j = i - count[i - 1]; j < i; j++)
			{
				if (s[j] == s[i])
					//����
				{
					count[i] = i - 1 - j;
				}
			}
			count[i] += 1;
			if (count[i]>max) max = count[i];
		}
		free(count);
		return max;
	}
};
int main()
{
	string s[] = { "pwwkew", "abcabcbb", "bbbbb", "abcdeffedcba" };
	Solution sol;
	for (int i = 0; i < 4; i++)
	{
		printf("%s:%d\n", s[i].c_str(), sol.lengthOfLongestSubstring(s[i]));
	}
	system("pause");
	return 0;
}