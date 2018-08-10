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
	int maxDepth(TreeNode* root)
	{
		if (!root)
			return 0;
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
} s;

int main()
{
	TreeNode *T1 = new TreeNode(3);
	T1->left = new TreeNode(9);
	T1->right = new TreeNode(20);
	T1->right->left = new TreeNode(15);
	T1->right->right = new TreeNode(7);
	cout << s.maxDepth(T1) << endl;
	system("pause");
	return 0;
}