#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	void rotate(vector<vector<int>>& matrix)
	{

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
	s.rotate(v1);
	s.rotate(v2);
	system("pause");
	return 0;
}