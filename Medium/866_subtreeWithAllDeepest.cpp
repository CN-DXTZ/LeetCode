#include<iostream>
#include<vector> 
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
	TreeNode * subtreeWithAllDeepest(TreeNode *root)
	{
		vector<vector<TreeNode*>> v;
		vector<TreeNode*> temp = { root };
		do
		{
			v.push_back(temp);
			temp.clear();
			for (int i = 0; i < v.back().size(); i++)
			{
				if (v.back()[i]->left)
					temp.push_back(v.back()[i]->left);
				if (v.back()[i]->right)
					temp.push_back(v.back()[i]->right);
			}
		} while (temp.size());

		int n = v.size() - 2;
		for (int i = 0; i < v[n].size(); i++)
			if (v[n][i]->left|| v[n][i]->right)
				return v[n][i];
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