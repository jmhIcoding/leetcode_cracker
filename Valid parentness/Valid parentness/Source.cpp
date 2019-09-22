#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
	bool pairss(char l, char r)
	{
		if (l == '(' && r == ')')
		{
			return 1;
		}
		if (l == '{' && r == '}')
			return 1;
		if (l == '[' && r == ']')
			return 1;
		return 0;
	}
	bool isValid(string s) {
		int n = s.length();
		vector<char>ss;
		int index = -1;
		for (int i = 0; i < n; i++)
		{
			if (s[i] != '(' && s[i] != ')' && s[i] != '[' && s[i] != ']' && s[i] != '{' && s[i] != '}')
				return 0;
			if (i)
			{
				if (index>=0 &&pairss(ss[index], s[i]))
				{
					ss.pop_back();
					index--;
				}
				else
				{
					ss.push_back(s[i]);
					index++;
				}
			}
			else
			{
				ss.push_back(s[i]);
				index++;
			}
		}
		return ss.empty() == 1;
	}
};
int main()
{
	Solution sol;
	printf("%d\n", sol.isValid("(){}"));
	system("pause");
	return 0;
}