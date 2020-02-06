#include<iostream>
#include<vector>
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
	// 法二: 递归
	vector<vector<int>> ans;
	void level_Order(TreeNode *node, int depth)
	{
		if (ans.size() == depth)
			ans.push_back(vector<int>());

		ans[depth].push_back(node->val);
		if (node->left)
			level_Order(node->left, depth + 1);
		if (node->right)
			level_Order(node->right, depth + 1);
	}
	vector<vector<int>> levelOrder(TreeNode *root)
	{
		if (root)
			level_Order(root, 0);
		return ans;
	}

	// 法一: 迭代
	//vector<vector<int>> levelOrder(TreeNode* root)
	//{
	//	vector<vector<int>> ans;
	//	if (!root)
	//		return ans;

	//	vector<int> curr_level;
	//	TreeNode * curr_node;
	//	queue<TreeNode *> nodes;
	//	nodes.push(root);
	//	int n;
	//	while (!nodes.empty())
	//	{
	//		n = nodes.size();
	//		curr_level.clear();
	//		while (n--)
	//		{
	//			curr_node = nodes.front();
	//			nodes.pop();

	//			curr_level.push_back(curr_node->val);
	//			if (curr_node->left)
	//				nodes.push(curr_node->left);
	//			if (curr_node->right)
	//				nodes.push(curr_node->right);
	//		}
	//		ans.push_back(curr_level);
	//	}
	//	return ans;
	//}
} s;

int main()
{
	TreeNode *T1 = new TreeNode(3);
	T1->left = new TreeNode(9);
	T1->right = new TreeNode(20);
	T1->right->left = new TreeNode(15);
	T1->right->right = new TreeNode(17);
	s.levelOrder(T1);
	s.levelOrder(NULL);
	system("pause");
	return 0;
}