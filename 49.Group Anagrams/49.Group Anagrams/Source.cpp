#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
	int hash(string & s)
	{
		long long int rst = 1;
		int mod = 1e9 + 7;
		int P = 19950817;
		for (int i = 0; i < s.size(); i++)
		{
			rst = (rst * P %mod + s[i]);
		}
		return rst;
	}
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string> > rst;
		vector<string> dups;
		map<int, int> hash2index;
		int index = 0;
		for (int i = 0; i < strs.size(); i++)
		{
			dups.push_back(strs[i]);
			sort(dups[i].begin(), dups[i].end());
			int hs = hash(dups[i]);
			if (hash2index.find(hs) == hash2index.end())
			{
				hash2index[hs] = index;
				index += 1;
				rst.push_back({});
			}
			rst[hash2index[hs]].push_back(strs[i]);
		}
		return rst;
	}
};
int main()
{
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	Solution sol;
		auto s = sol.groupAnagrams(strs);
		printf("%d\n", s.size());
		system("pause");
	return 0;
}