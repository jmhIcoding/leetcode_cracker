#include <string>
#include <set>
using namespace std;
class Solution {
public:
	bool isValid(int length, int index)
	{
		return index >= 0 && index < length;
	}
	string longestPalindrome(string s) {
		int mid=0,l=s.length();
		size_t st=0, max = 1;
		for (mid = 0; mid < l; mid++)
		{
			int i;
			//奇数情况
			//可以预判断一下
			if((!(isValid(l, mid + (max-1)/2) && isValid(l, mid - (max-1)/2) && s[mid + (max-1)/2] == s[mid - (max-1)/2])) && !(isValid(l, mid + max/2 + 1) && isValid(l, mid - max/2) && s[mid + max/2 + 1] == s[mid - max/2]))
			{
				continue;
			}
			for (i = 1; i <l;)
			{
				if (isValid(l, mid + i) && isValid(l, mid - i) && s[mid + i] == s[mid - i])
				{
					i++;
				}
				else
				{
					break;
				}
			}
			i--;
			if ((i * 2 + 1) > max)
			{
				max = i * 2 + 1;
				st = mid - i;
			}
			//偶数情况
			for (i = 0; i < l;)
			{
				if (isValid(l, mid-i) && isValid(l, mid+i+1)&& s[mid-i] == s[mid +i+1])
				{
					i++;
				}
				else
				{
					break;
				}
			}
			i--;
			if (2 * (i + 1) > max)
			{
				max = (i+1) * 2;
				st = mid - i;
			}
		}
		return s.substr(st, max);
	}
};
int main()
{
	string s[] = { "babad", "a", "cbbd", "abcdcba" ,"aeee","aee","ae","abcdedc23"};
	Solution sol;
	for (int i = 0; i < 8; i++)
	{
		printf("%s,%s\n", s[i].c_str(), sol.longestPalindrome(s[i]).c_str());
	}
	system("pause");
	return 0;
}