#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
	// 法二:
	string countAndSay(int n)
	{
		if (n == 1)
			return "1";
		string re = countAndSay(n - 1);
		string result;
		int count = 1;
		for (int i = 0; i < re.size() - 1; i++)
		{
			if (re[i + 1] == re[i])
				count++;
			else
			{
				result.push_back(count + '0');
				result.push_back(re[i]);
				count = 1;
			}
		}
		result.push_back(count + '0');
		result.push_back(re[re.size() - 1]);
		return result;
	}

	// 法一:
	//string countAndSay(int n)
	//{
	//	string ans = "1";
	//	n--;
	//	while (n--)
	//	{
	//		string str = "";
	//		int cnt = 1;
	//		for (int i = 0; i < ans.size() - 1; i++)
	//		{
	//			if (ans[i] == ans[i + 1])
	//				cnt++;
	//			else
	//			{
	//				str = str + (char)(cnt + '0') + ans[i];
	//				cnt = 1;
	//			}
	//		}
	//		ans = str + (char)(cnt + '0') + ans[ans.size() - 1];
	//		cout << ans << endl;
	//	}
	//	return ans;
	//}
} s;

int main()
{
	cout << s.countAndSay(1) << endl;
	cout << s.countAndSay(4) << endl;
	system("pause");
	return 0;
}