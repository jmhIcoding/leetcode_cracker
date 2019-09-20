#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
	struct _interval
	{
		int s, e;
		bool operator < (const _interval & rhs) const
		{
			return s < rhs.s || (s==rhs.s && e<rhs.e);
		}
	};
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int >> rst;
		set<_interval> ints;
		for (int i = 0; i < intervals.size(); i++)
		{
			ints.insert({ intervals[i][0], intervals[i][1] });
		}
		while (true)
		{
			int flag = true;
			for (auto it = ints.begin(); it != ints.end(); it++)
			{
				auto now = it++;
				auto next = it;
				if (next != ints.end())
				{
					if (now->e >= next->s)
					{
						//merge
						_interval _newinterval = { now->s,max(next->e,now->e) };
						ints.erase(now);
						ints.erase(next);
						ints.insert(_newinterval);
						flag = false;
						it = now;
						break;
					}

				}
				it = now;
			}
			if (flag == true)
			{
				break;
			}
		}
		for (auto each : ints)
		{
			rst.push_back({ each.s,each.e });
		}
		return rst;
	}
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		intervals.push_back(newInterval);
		return merge(intervals);
	}
};
int main()
{
	Solution sol;
	vector< vector<int> > ints = { {1,3},{2,6 },{8,10},{15,18} };
	auto rst = sol.merge(ints);
	printf("%d\n", rst.size());
	system("pause");
	return 0;
}