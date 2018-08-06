#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	// 法二:
	bool isAnagram(string s, string t)
	{
		if (s.length() != t.length())
			return false;

		int n = s.length();
		int counts[127] = { 0 };
		for (int i = 0; i < n; i++)
		{
			counts[s[i]]++;
			counts[t[i]]--;
		}
		for (int i = 'a'; i <= 'z'; i++)
			if (counts[i])
				return false;
		return true;
	}
	// 法一:
	//bool isAnagram(string s, string t)
	//{
	//	if (s.length() != t.length())
	//		return false;

	//	unordered_map<char, int> dict;
	//	for (char ch : s)
	//		dict[ch]++;
	//	for (char ch : t)
	//		dict[ch]--;
	//	for (auto it : dict)
	//		if (it.second)
	//			return false;
	//	return true;
	//}
} s;

int main()
{
	cout << s.isAnagram("anagram", "nagaram") << endl;
	cout << s.isAnagram("rat", "car") << endl;
	system("pause");
	return 0;
}