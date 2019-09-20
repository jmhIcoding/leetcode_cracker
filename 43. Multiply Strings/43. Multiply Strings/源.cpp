#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	string multiply(string num1, string num2) {
		vector<int> rst(num1.size() + num2.size() + 10);
		for(int i =0;i<rst.size();i++)
		{
			rst[i] = 0;
		}
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		for (int i = 0; i < num1.size(); i++)
		{
			for (int j = 0; j < num2.size(); j++)
			{
				rst[i + j + 1] += (rst[i + j] + (num1[i]-'0') * (num2[j]-'0')) / 10;
				rst[i + j] = (rst[i + j] + (num1[i]-'0') * (num2[j]-'0')) % 10;
			}
		}
		int mostC = 0;
		for (int i = 0; i < rst.size(); i++)
		{
			if (rst[i])
			{
				mostC = i;
			}
		}
		string str;
		for (int i = 0; i <= mostC; i++)
		{
			str.push_back(rst[i]+'0');
		}
		reverse(str.begin(), str.end());
		return str;
	}
};
int main()
{

	Solution sol;
	string num1 = "0", num2 = "456";
	printf("%s\n", sol.multiply(num1,num2).c_str());
	system("pause");
	return 0;
}