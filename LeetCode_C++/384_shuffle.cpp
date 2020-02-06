#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

class Solution {
	vector<int> nums;
public:
	Solution(vector<int> nums) {
		this->nums = nums;
	}

	vector<int> reset() {
		return nums;
	}

	vector<int> shuffle() {
		vector<int> result(nums);
		int n = result.size(), new_idx;
		//srand(time(NULL));
		for (int i = 0; i < n; i++)
		{
			new_idx = rand() % n;
			swap(result[i], result[new_idx]);
		}
		return result;
	}
};


int main()
{
	vector<int> nums = { 1,2,3,4,5 };
	Solution *obj = new Solution(nums);
	vector<int> param_1 = obj->reset();
	vector<int> param_2 = obj->shuffle();
	system("pause");
	return 0;
}