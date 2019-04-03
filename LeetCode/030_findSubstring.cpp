#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution
{
public:
	vector<int> findSubstring(string s, vector<string>& words)
	{
		vector<int> ans;
		if (s.empty() || words.empty())
			return ans;

		int len_s = s.size(), num_word = words.size(), len_word = words[0].size();
		// 存储单词列表
		unordered_map<string, int> dict;
		for (string word : words)
			dict[word]++;

		// 遍历子串起始位置
		for (int idx = 0; idx <= len_s - num_word * len_word; idx++)
		{

			unordered_map<string, int> temp_dict;
			int t_num_word = 0;
			// 遍历子串所有单词
			for (; t_num_word < num_word; t_num_word++)
			{
				string curr_word = s.substr(idx + t_num_word * len_word, len_word);
				if (dict.find(curr_word) != dict.end())
				{
					temp_dict[curr_word]++;
					if (temp_dict[curr_word] > dict[curr_word])
						break;
				}
				else break;
			}
			if (t_num_word == num_word)
				ans.push_back(idx);
		}
		return ans;
	}
} s;

int main()
{
	string s1 = "barfoothefoobarman", s2 = "wordgoodstudentgoodword";
	vector<string> words1 = { "foo","bar" }, words2 = { "word","student" };
	s.findSubstring(s1, words1);
	s.findSubstring(s2, words2);

	system("pause");
	return 0;
}
