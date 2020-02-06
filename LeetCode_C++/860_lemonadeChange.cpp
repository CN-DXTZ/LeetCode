#include<iostream>
#include<vector> 
using namespace std;
class Solution
{
public:
	bool lemonadeChange(vector<int>& bills)
	{
		int a[2] = { 0 };
		for (int i = 0; i < bills.size(); i++)
		{
			if (bills[i] == 5)
				a[0]++;
			else if (bills[i] == 10)
			{
				if (a[0])
					a[0]--, a[1]++;
				else
					return false;
			}
			else if (bills[i] == 20)
			{
				if (a[0] && a[1])
					a[0]--, a[1]--;
				else if (a[0] > 2)
					a[0] -= 3;
				else
					return false;
			}
		}
		return true;
	}
} s;

int main()
{
	vector<int> v1 = { 5,5,5,10,20 };
	vector<int> v2 = { 5,5,10 };
	vector<int> v3 = { 10,10 };
	vector<int> v4 = { 5,5,10,10,20 };
	vector<int> v5 = { 5,5,5,5,20,20,5,5,20,5 };
	vector<int> v6 = { 5,5,20,5,5,10,5,10,5,20 };
	cout << s.lemonadeChange(v1) << endl;;
	cout << s.lemonadeChange(v2) << endl;;
	cout << s.lemonadeChange(v3) << endl;;
	cout << s.lemonadeChange(v4) << endl;;
	cout << s.lemonadeChange(v5) << endl;;
	cout << s.lemonadeChange(v6) << endl;;
	system("pause");
	return 0;
}