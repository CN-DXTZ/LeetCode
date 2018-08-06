#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	void rotate(vector<vector<int>>& matrix)
	{
		int  n = matrix.size() - 1;
		int len_row = matrix.size() / 2, len_column = (matrix.size() + 1) / 2;
		for (int i = 0; i < len_row; i++)
			for (int j = 0; j < len_column; j++)
			{
				int temp = matrix[i][j];
				matrix[i][j] = matrix[n - j][i];
				matrix[n - j][i] = matrix[n - i][n - j];
				matrix[n - i][n - j] = matrix[j][n - i];
				matrix[j][n - i] = temp;
			}
	}
} s;

int main()
{
	vector<vector<int>> v1 =
	{ {1, 2, 3},
	  {4, 5, 6},
	  {7, 8, 9} };
	vector<vector<int>> v2 =
	{ {5,	1,	9,	11},
	  {2,	4,	8,	10},
	  {13,	3,	6,	7},
	  {15,	14,	12,	16} };
	vector<vector<int>> v3 =
	{ { 1, 2 },
	  { 4, 5 } };
	vector<vector<int>> v4 =
	{ { 5} };
	s.rotate(v1);
	s.rotate(v2);
	s.rotate(v3);
	s.rotate(v4);
	system("pause");
	return 0;
}