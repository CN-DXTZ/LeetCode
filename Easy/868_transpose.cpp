#include<iostream>
#include<vector> 
using namespace std;

class Solution
{
public:
	vector<vector<int>> transpose(vector<vector<int>>& A)
	{
		int row = A.size(), column = A[0].size();
		vector<vector<int>> ans(row);

		for (int j = 0; j < column; j++)
		{
			vector<int> temp;
			for (int i = 0; i < row; i++)
			{
				temp.push_back(A[i][j]);
			}
			ans.push_back(temp);
		}
		return ans;
	}
} s;

int main()
{
	vector<vector<int>> v1 = { { 1,2,3 },{ 4,5,6 },{ 7,8,9 } };
	vector<vector<int>> v2 = { { 1,2,3 },{ 4,5,6 }};
	s.transpose(v1);
	s.transpose(v2);
	system("pause");
	return 0;
}