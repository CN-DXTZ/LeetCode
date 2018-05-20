#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
class Solution
{
public:
	int maxArea(vector<int>& height)
	{
		int ans = 0;
		int i = 0, j = height.size() - 1;
		while (i < j)
		{
			int h = min(height[i], height[j]);
			ans = max(ans, (j - i)*h);
			// 跳过高度更小的
			while (height[i] <= h && i < j)
				i++;
			while (height[j] <= h && i < j)
				j--;
		}
		return ans;
	}
} s;

int main()
{
	vector<int> a = { 3,2,3,4,5 };
	cout << s.maxArea(a) << endl;
	system("pause");
	return 0;
}