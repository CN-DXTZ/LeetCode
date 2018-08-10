#include<iostream>
#include<algorithm>
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
	// 法一: 顺序深搜应升序
	int before = INT_MIN;
	bool isValidBST(TreeNode* root)
	{
		before = INT_MIN;
		return is_Valid_BST(root);
	}
	bool is_Valid_BST(TreeNode* root)
	{
		if (!root)
			return true;
		if (!is_Valid_BST(root->left))
			return false;
		if (root->val <= before)
			return false;
		before = root->val;
		return is_Valid_BST(root->right);
	}
} s;

int main()
{
	TreeNode *T1 = new TreeNode(6);
	T1->left = new TreeNode(2);
	T1->left->left = new TreeNode(1);
	T1->left->right = new TreeNode(4);
	T1->left->right->left = new TreeNode(3);
	T1->left->right->right = new TreeNode(5);
	T1->right = new TreeNode(8);
	T1->right->left = new TreeNode(7);
	T1->right->right = new TreeNode(9);
	TreeNode *T2 = new TreeNode(2);
	T2->left = new TreeNode(1);
	T2->right = new TreeNode(3);
	TreeNode *T3 = new TreeNode(5);
	T3->left = new TreeNode(1);
	T3->right = new TreeNode(4);
	T3->right->left = new TreeNode(3);
	T3->right->right = new TreeNode(6);
	TreeNode *T4 = new TreeNode(0);
	//cout << s.isValidBST(T1) << endl;
	//cout << s.isValidBST(T2) << endl;
	cout << s.isValidBST(T3) << endl;
	//cout << s.isValidBST(T4) << endl;
	//cout << s.isValidBST(NULL) << endl;
	system("pause");
	return 0;
}