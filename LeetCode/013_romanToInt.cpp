#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int romanToInt(string s)
	{
		unordered_map<char, int> T = { { 'I' , 1 },
		{ 'V' , 5 },{ 'X' , 10 },{ 'L' , 50 },
		{ 'C' , 100 },{ 'D' , 500 },{ 'M' , 1000 } };

		// 最后一个数一定是正的
		int sum = T[s.back()];
		for (int i = s.length() - 2; i >= 0; --i)
		{
			if (T[s[i]] < T[s[i + 1]])
				sum -= T[s[i]];
			else
				sum += T[s[i]];
		}

		return sum;
	}
} s;

int main()
{
	cout << s.romanToInt("III") << endl;
	cout << s.romanToInt("IV") << endl;
	cout << s.romanToInt("IX") << endl;
	cout << s.romanToInt("LVIII") << endl;
	cout << s.romanToInt("MCMXCIV") << endl;
	system("pause");
	return 0;
}