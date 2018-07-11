#include<iostream>
#include<vector> 
#include<map> 
#include<string>
using namespace std;
class Solution
{
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> v;
		if (n == 0)
			return v;

		map<string, int> m[2];
		m[0].insert(make_pair("(", 1));

		bool flag = 1;
		for (int i = 2; i < 2 * n; i++)
		{
			m[flag].clear();
			auto it = m[!flag].begin();
			while (it != m[!flag].end())
			{
				if (it->second > 0)
					m[flag].insert(make_pair((it->first + ')'), it->second - 1));
				if (i + it->second <= 2 * n)
					m[flag].insert(make_pair((it->first + '('), it->second + 1));
				it++;
			}
			flag = !flag;
		}
		auto it = m[0].begin();
		while (it != m[0].end())
		{
			v.push_back(it->first + ')');
			it++;
		}
		return v;
	}
} s;

int main()
{
	s.generateParenthesis(3);
	system("pause");
	return 0;
}
