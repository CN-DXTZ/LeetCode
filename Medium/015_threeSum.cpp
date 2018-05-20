#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
class Solution
{
public:
	vector<int> v;
	vector<vector<int> > threeSum(vector<int>& nums)
	{
		v = nums;
		int n = v.size();
		vector<vector<int> > ans;

		if (!n)
			return ans;

		sort(v.begin(), v.end());

		// 剪枝: 小数<=0
		for (int i = 0; v[i] <= 0 && i < n - 2; i++)
		{
			// 剪枝: 重复
			if (i&&v[i] == v[i - 1])
				continue;
			// 剪枝: v[i] + 2 * v[j] <= 0
			for (int j = i + 1; v[i] + 2 * v[j] <= 0 && j < n - 1; j++)
			{
				// 剪枝: 重复
				if (j - i != 1 && v[j] == v[j - 1])
					continue;
				int k = binarySearch(j + 1, -v[i] - v[j]);
				if (k > 0)
					ans.push_back({ v[i],v[j], v[k] });
			}

		}
		return ans;
	}
	// 二分查找
	int binarySearch(int begin, int target)
	{
		int min = begin, max = v.size() - 1, mid;
		while (max - min > 1)
		{
			mid = (max - min) / 2 + min;
			if (v[mid] == target)
				return mid;
			else if (v[mid] > target)
				max = mid;
			else
				min = mid;
		}
		if (v[min] == target)
			return min;
		else if (v[max] == target)
			return max;
		else
			return -1;
	}
} s;

int main()
{
	vector<int> a = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int> > ans = s.threeSum(a);
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j];
		cout << endl;
	}
	system("pause");
	return 0;
}