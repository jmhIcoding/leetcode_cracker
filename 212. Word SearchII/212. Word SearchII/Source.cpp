#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <map>
using namespace std;
//回溯的题目,跟着所给的串进行搜索。
class Solution {
public:
	bool isValid(int x, int y, vector<vector<char>> & grid, vector<vector<int>> & paths, int m, int n)
	{
		if (x < 0 || y < 0 || x >= m || y >= n || paths[x][y] == 1)
		{
			return false;
		}
		return true;
	}
	int backtrace(vector<vector<char> > & grid, vector<vector<int>> & paths, int depth, int& m, int& n, int x, int y, int& required, string &tmpS, string &target)
	{
		int rst = 0;
		if (depth == required && target == tmpS)
		{
			return 1;
		}
		if (depth >= required) return 0;
		for (int i = 0; i < 4; i++)
		{
			switch (i)
			{
			case 0:
				if (isValid(x + 1, y, grid, paths, m, n) && grid[x+1][y]==target[depth])
				{
					paths[x + 1][y] = 1;
					tmpS.push_back(grid[x + 1][y]);
					rst += backtrace(grid, paths, depth + 1, m, n, x + 1, y, required, tmpS, target);
					tmpS.pop_back();
					paths[x + 1][y] = 0;
				}
				break;
			case 1:
				if (isValid(x - 1, y, grid, paths, m, n) && grid[x - 1][y] == target[depth])
				{
					paths[x - 1][y] = 1;
					tmpS.push_back(grid[x - 1][y]);
					rst += backtrace(grid, paths, depth + 1, m, n, x - 1, y, required, tmpS, target);
					tmpS.pop_back();
					paths[x - 1][y] = 0;
				}
				break;
			case 2:
				if (isValid(x, y + 1, grid, paths, m, n) && grid[x][y+1] == target[depth])
				{
					paths[x][y + 1] = 1;
					tmpS.push_back(grid[x][y + 1]);
					rst += backtrace(grid, paths, depth + 1, m, n, x, y + 1, required, tmpS, target);
					tmpS.pop_back();
					paths[x][y + 1] = 0;
				}
				break;
			case 3:
				if (isValid(x, y - 1, grid, paths, m, n) && grid[x][y-1] == target[depth])
				{
					paths[x][y - 1] = 1;
					tmpS.push_back(grid[x][y - 1]);
					rst += backtrace(grid, paths, depth + 1, m, n, x, y - 1, required, tmpS, target);
					tmpS.pop_back();
					paths[x][y - 1] = 0;
				}
				break;
			default:
				break;
			}
			if (rst)
				return rst;
		}
		return rst;
	}
	struct _pos
	{
		int x, y;
	};
	vector<string> findWords(vector<vector<char>>& grid, vector<string>& words) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> paths;
		int required = 0;
		int x, y;
		vector<string> rst;
		map<char, vector<_pos> > char_start;
		for (int i = 0; i < m; i++)
		{
			paths.push_back({});
			for (int j = 0; j < n; j++)
			{
				char_start[grid[i][j]].push_back({ i, j });
				paths[i].push_back(0);
			}
		}
		for (int i = 0; i < words.size(); i++)
		{
			int count[27] = { 0 };
			//剪枝
			for (int j = 0; j < words[i].size(); j++)
			{
				count[words[i][j] - 'a']++;
				if (char_start.find(words[i][j]) == char_start.end())
				{
					continue;
				}
				else if (char_start[words[i][j]].size()<count[words[i][j] - 'a'])
				{
					continue;
				}
			}

			for (auto each : char_start[words[i][0]])
			{
				x = each.x;
				y = each.y;

				paths[x][y] = 1;
				string tmpS(1, words[i][0]);
				required = words[i].size();
				if (backtrace(grid, paths, 1, m, n, x, y, required, tmpS, words[i]))
				{
					paths[x][y] = 0;
					rst.push_back(words[i]);
					//printf("%s\n", words[i].c_str());
					break;
				}
				paths[x][y] = 0;
			}
		}
		return rst;
	}
};
int main()
{
	Solution sol;
	vector<vector <char >> grid = {{'b', 'a', 'a', 'b', 'a', 'b'}, {'a', 'b', 'a', 'a', 'a', 'a'}, {'a', 'b', 'a', 'a', 'a', 'b'}, {'a', 'b', 'a', 'b', 'b', 'a'}, {'a', 'a', 'b', 'b', 'a', 'b'}, {'a', 'a', 'b', 'b', 'b', 'a'}, {'a', 'a', 'b', 'a', 'a', 'b'}};
	vector<string> words = { "bbaabaabaaaaabaababaaaaababb", "aabbaaabaaabaabaaaaaabbaaaba", "babaababbbbbbbaabaababaabaaa", "bbbaaabaabbaaababababbbbbaaa", "babbabbbbaabbabaaaaaabbbaaab", "bbbababbbbbbbababbabbbbbabaa", "babababbababaabbbbabbbbabbba", "abbbbbbaabaaabaaababaabbabba", "aabaabababbbbbbababbbababbaa", "aabbbbabbaababaaaabababbaaba", "ababaababaaabbabbaabbaabbaba", "abaabbbaaaaababbbaaaaabbbaab", "aabbabaabaabbabababaaabbbaab", "baaabaaaabbabaaabaabababaaaa", "aaabbabaaaababbabbaabbaabbaa", "aaabaaaaabaabbabaabbbbaabaaa", "abbaabbaaaabbaababababbaabbb", "baabaababbbbaaaabaaabbababbb", "aabaababbaababbaaabaabababab", "abbaaabbaabaabaabbbbaabbbbbb", "aaababaabbaaabbbaaabbabbabab", "bbababbbabbbbabbbbabbbbbabaa", "abbbaabbbaaababbbababbababba", "bbbbbbbabbbababbabaabababaab", "aaaababaabbbbabaaaaabaaaaabb", "bbaaabbbbabbaaabbaabbabbaaba", "aabaabbbbaabaabbabaabababaaa", "abbababbbaababaabbababababbb", "aabbbabbaaaababbbbabbababbbb", "babbbaabababbbbbbbbbaabbabaa" };
	printf("%d\n", sol.findWords(grid, words).size());
	system("pause");
	return 0;
}