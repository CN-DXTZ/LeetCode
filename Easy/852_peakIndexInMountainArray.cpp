#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int peakIndexInMountainArray(vector<int>& A)
	{
		int left = 0, right = A.size() - 1;
		while (left < right)
		{
			int mid = (left + right) >> 1;
			if (A[mid] < A[mid + 1])
				left = mid + 1;
			else
				right = mid;
		}
		return  left;
	}
} s;

int main()
{
	vector<int> a1 = { 0,1,0 };
	vector<int> a2 = { 0,2,1,0 };
	cout << s.peakIndexInMountainArray(a1) << endl;
	cout << s.peakIndexInMountainArray(a2) << endl;
	system("pause");
	return 0;
}