#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	vector<int> v;
	int findPeakElement(vector<int>& nums)
	{
		v = nums;
		int min = 0, max = v.size() - 1, mid;
		while (abs(max - min) > 1)
		{
			mid = (max - min) / 2 + min;
			int flag1 = cmp_max(mid, mid - 1), flag2 = cmp_max(mid + 1, mid);
			if (flag1 && !flag2)//·å
				return mid;
			else if (flag1 && flag2)//Ôö
				min = mid;
			else
				max = mid;
		}
		if (cmp_max(min, min - 1) && !cmp_max(min + 1, min))
			return min;
		return max;

	}
	bool cmp_max(int i, int j)
	{
		if (j == -1)
			return 1;
		else if (i == v.size())
			return 0;
		else
			return v[i] > v[j];
	}
} s;

int main()
{
	vector<int> a = { 1,2 };
	cout << s.findPeakElement(a) << endl;
	system("pause");
	return 0;
}