#include<iostream>
#include<vector> 
#include<algorithm>
#include<cmath>
using namespace std;
class Solution
{
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> a(numRows);
		for (int i = 0; i < numRows; i++)
		{
			a[i].resize(i + 1);
			a[i][0] = a[i][i] = 1;
			for (int j = 1; j < i; j++)
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
		return a;
	}
} s;

int main()
{
	auto ans = s.generate(5);
	system("pause");
	return 0;
}
