#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution
{
public:
	//��һ:����+����
	void wiggleSort(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		vector<int> tmp = nums;
		int len = nums.size();
		int k = len - 1;
		//��֤����С�󣬴�С��СС����Ϊ��С��С��ʱֵ������ͬ
		//����
		for (int i = 1; i < len; i += 2)
			nums[i] = tmp[k--];
		//С��
		for (int i = 0; i < len; i += 2)
			nums[i] = tmp[k--];
	}
} s;

int main()
{
	vector<int> nums = { 4,5,5,6 };
	s.wiggleSort(nums);
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << endl;
	system("pause");
	return 0;
}