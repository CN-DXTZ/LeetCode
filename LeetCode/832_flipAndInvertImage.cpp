#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A)
	{
		if (A.empty())
			return A;
		int n = A.size(), m = A[0].size(), temp;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < (m + 1) / 2; j++)
			{
				temp = A[i][j];
				A[i][j] = !A[i][m - 1 - j];
				A[i][m - 1 - j] = !temp;
			}
		return A;
	}
} s;

int main()
{
	vector<vector<int>> v1 = { {1,1,0},{ 1,0,1 },{ 0,0,0 } };
	vector<vector<int>> v2 = { {1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0} };
	auto ans1 = s.flipAndInvertImage(v1);
	auto ans2 = s.flipAndInvertImage(v2);

	system("pause");
	return 0;
}