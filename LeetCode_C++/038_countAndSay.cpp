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
		string previous = countAndSay(n - 1);
		string ans;
		int cnt = 1;
		for (int i = 0; i < previous.size() - 1; i++)
		{
			if (previous[i + 1] == previous[i])
				cnt++;
			else
			{
				ans.push_back(cnt + '0');
				ans.push_back(previous[i]);
				cnt = 1;
			}
		}
		ans.push_back(cnt + '0');
		ans.push_back(previous[previous.size() - 1]);
		return ans;
	}

	// 法一:
	//string countAndSay(int n)
	//{
	//	string ans = "1";
	//	while (--n)
	//	{
	//		string temp;
	//		int cnt = 1;
	//		for (int i = 0; i < ans.size() - 1; i++)
	//		{
	//			if (ans[i] == ans[i + 1])
	//				cnt++;
	//			else
	//			{
	//				temp.push_back(cnt + '0');
	//				temp.push_back(ans[i]);
	//				cnt = 1;
	//			}
	//		}
	//		temp.push_back(cnt + '0');
	//		temp.push_back(ans[ans.size() - 1]);
	//		ans = temp;
	//		//cout << ans << endl;
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