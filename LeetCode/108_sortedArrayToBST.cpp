#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode  *left;
	TreeNode  *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
	// 递归
	// 法二: 时间O(n),空间O(1)
	TreeNode * sortedArrayToBST(vector<int>& nums)
	{
		return sorted_Array_To_BST(nums, 0, nums.size());
	}
	TreeNode * sorted_Array_To_BST(vector<int>& nums, int begin, int end)
	{
		if (begin == end)
			return NULL;

		int mid = (begin + end) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = sorted_Array_To_BST(nums, begin, mid);
		root->right = sorted_Array_To_BST(nums, mid + 1, end);
		return root;
	}

	// 法一: 时间O(n),空间O(n)
	//TreeNode * sortedArrayToBST(vector<int> &num)
	//{
	//	if (num.size() == 0)
	//		return NULL;

	//	int mid = num.size() / 2;
	//	vector<int> leftInts(num.begin(), num.begin() + mid);
	//	vector<int> rightInts(num.begin() + mid + 1, num.end());

	//	TreeNode* root = new TreeNode(num[mid]);
	//	root->left = sortedArrayToBST(leftInts);
	//	root->right = sortedArrayToBST(rightInts);
	//	return root;
	//}
} s;

int main()
{
	vector<int> v1 = { -10,-3,0,5,9 };
	auto a = s.sortedArrayToBST(v1);
	system("pause");
	return 0;
}