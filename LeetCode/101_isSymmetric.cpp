#include<iostream>
#include<queue>
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
	// 法二: 迭代
	bool isSymmetric(TreeNode* root)
	{
		TreeNode *left, *right;
		if (!root)
			return true;

		queue<TreeNode*> q1, q2;
		q1.push(root->left);
		q2.push(root->right);
		while (!q1.empty() && !q2.empty())
		{
			left = q1.front(), right = q2.front();
			q1.pop(), q2.pop();

			if (!left && !right)
				continue;
			else if (!left || !right)
				return false;
			if (left->val != right->val)
				return false;
			q1.push(left->left);
			q1.push(left->right);
			q2.push(right->right);
			q2.push(right->left);
		}
		return true;
	}

	// 法一: 递归
	//bool isSymmetric(TreeNode* root)
	//{
	//	if (!root)
	//		return true;
	//	return is_Symmetric(root->left, root->right);
	//}
	//bool is_Symmetric(TreeNode* left, TreeNode* right)
	//{
	//	if (!left && !right)
	//		return true;
	//	else if (!left || !right)
	//		return false;
	//	
	//	if (left->val != right->val)
	//		return false;
	//	return is_Symmetric(left->left, right->right) && is_Symmetric(left->right, right->left);
	//}
} s;

int main()
{
	TreeNode *T1 = new TreeNode(1);
	T1->left = new TreeNode(2);
	T1->left->left = new TreeNode(3);
	T1->left->right = new TreeNode(4);
	T1->right = new TreeNode(2);
	T1->right->left = new TreeNode(4);
	T1->right->right = new TreeNode(3);
	TreeNode *T2 = new TreeNode(1);
	T2->left = new TreeNode(2);
	T2->left->right = new TreeNode(3);
	T2->right = new TreeNode(2);
	T2->right->right = new TreeNode(3);
	cout << s.isSymmetric(T1) << endl;
	cout << s.isSymmetric(T2) << endl;
	cout << s.isSymmetric(NULL) << endl;
	system("pause");
	return 0;
}