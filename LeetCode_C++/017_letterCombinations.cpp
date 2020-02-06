#include<iostream>
#include<vector> 
#include<string> 
using namespace std;
class Solution
{
public:
	vector<vector<string>> chs = { { "a","b","c" },{ "d","e","f" },{ "g","h","i" },
							{ "j","k","l" },{ "m","n","o" },{ "p","q","r","s" },
							{ "t","u","v" },{ "w","x","y","z" } };
	vector<string>  letterCombinations(string digits)
	{
		vector<string> vec_str;
		if (digits.empty())
			return vec_str;
		
		vector<string> son = letterCombinations(digits.substr(1));
		if (son.empty())
			son.push_back("");

		int idx = digits[0] - '2';
		for (int i = 0; i < chs[idx].size(); i++)
		{
			for (int j = 0; j < son.size(); j++)
			{
				string curr_ch = chs[idx][i];
				curr_ch.append(son[j]);
				vec_str.push_back(curr_ch);
			}
		}
		return vec_str;
	}
} s;

int main()
{
	vector<string> ans = s.letterCombinations("23");
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	system("pause");
	return 0;
}
