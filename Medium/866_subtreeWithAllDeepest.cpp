#include<iostream>
#include<map>
#include<set>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode  *left;
	TreeNode  *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	int deepLength = 0;
	set<TreeNode *> deepNode;
	map<TreeNode *, TreeNode *> father;
	TreeNode * subtreeWithAllDeepest(TreeNode *root)
	{
		dfs(root, 1);
		find();
		return *(deepNode.begin());
	}
	// 找到最深节点的共同最深父节点
	void find()
	{
		while (deepNode.size() != 1)
		{
			set<TreeNode *> upper;
			auto it = deepNode.begin();
			while (it != deepNode.end())
				upper.insert(father[*it++]);
			deepNode = upper;
		}
	}
	// 深搜找到最深节点并保存每个节点的父节点
	void dfs(TreeNode *p, int depth)
	{
		if (depth > deepLength)
		{
			deepLength = depth;
			deepNode.clear();
			deepNode.insert(p);
		}
		else if (depth == deepLength)
			deepNode.insert(p);

		if (p->left)
		{
			father.insert(make_pair(p->left, p));
			dfs(p->left, depth + 1);
		}
		if (p->right)
		{
			father.insert(make_pair(p->right, p));
			dfs(p->right, depth + 1);
		}
	}
} s;

int main()
{
	TreeNode *T1 = new TreeNode(3);
	T1->left = new TreeNode(5);
	T1->left->left = new TreeNode(6);
	T1->left->right = new TreeNode(2);
	T1->left->right->left = new TreeNode(7);
	T1->left->right->right = new TreeNode(4);
	T1->right = new TreeNode(1);
	T1->right->left = new TreeNode(0);
	T1->right->right = new TreeNode(8);
	s.subtreeWithAllDeepest(T1);
	system("pause");
	return 0;
}