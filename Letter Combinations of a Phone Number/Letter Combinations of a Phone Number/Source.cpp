#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	Solution()
	{
		 maps = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	}
public:
	vector<string>& backsource(string& digits, int index,string &prefix)
	{
		vector<string > *rst=new vector<string>();
		if (index == (digits.size()))
		{
			rst->push_back(prefix);
			return *rst;
		}
		int number = digits[index] - '0';
		
		for (int i = 0; i < maps[number].size(); i++)
		{
			auto r = backsource(digits, index + 1, prefix.append(1, maps[number][i]));
			for (int j = 0; j < r.size(); j++)
			{
				rst->push_back(r[j]);
			}
			prefix.pop_back();
		}
		return *rst;
	}
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0) return{};
		string empty("");
		return backsource(digits, 0, empty);
	}
public:
	vector<string> maps;
};

int main()
{
	Solution sol;
	vector<string > test = { "23" };
	for (int i = 0; i < test.size(); i++)
	{
		auto rst = sol.letterCombinations(test[i]);
		for (int j = 0; j < rst.size(); j++)
		{
			printf("%d:%s\n",j, rst[j].c_str());
		}
	}
	system("pause");
	return 0;
}