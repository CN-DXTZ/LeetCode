#include<iostream>
#include<vector> 
#include<algorithm> 
using namespace std;

class Solution
{
public:
	// 法二:
	vector<int> plusOne(vector<int>& digits)
	{
		int n = digits.size();
		for (int i = n - 1; i >= 0; --i)
		{
			if (digits[i] == 9)
				digits[i] = 0;
			else
			{
				digits[i]++;
				return digits;
			}
		}
		digits[0] = 1;
		digits.push_back(0);
		return digits;
	}
	// 法一:
	//vector<int> plusOne(vector<int>& digits)
	//{
	//	vector<int> ans;
	//	int temp = 0, C = 1;
	//	for (int i = digits.size() - 1; i >= 0; i--)
	//	{
	//		temp = digits[i] + C;
	//		C = 0;
	//		if (temp == 10)
	//		{
	//			if (i)
	//				temp = 0, C = 1;
	//			else
	//			{
	//				ans.push_back(0);
	//				ans.push_back(1);
	//				break;
	//			}
	//		}
	//		ans.push_back(temp);
	//	}
	//	reverse(ans.begin(), ans.end());
	//	return ans;
	//}
} s;

int main()
{
	vector<int> v0 = { 1,2,3 };
	vector<int> v1 = { 4,3,2,1 };
	vector<int> v2 = { 4,9,9,9 };
	vector<int> v3 = { 9,9,9,9 };
	s.plusOne(v0);
	s.plusOne(v1);
	s.plusOne(v2);
	s.plusOne(v3);
	system("pause");
	return 0;
}