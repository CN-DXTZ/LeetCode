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
	// 法二: 确定每个节点的极值节点并遍历
	bool isValidBST(TreeNode* root) {
		return is_Valid_BST(root, NULL, NULL);
	}

	bool is_Valid_BST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
	{
		if (!root) 
			return true;
		if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val))
			return false;
		return is_Valid_BST(root->left, minNode, root) && is_Valid_BST(root->right, root, maxNode);
	}
	// 法一: 顺序深搜遍历应为升序排列
	//TreeNode * prev = NULL;
	//bool isValidBST(TreeNode* root)
	//{
	//	prev = NULL;
	//	return is_Valid_BST(root);
	//}
	//bool is_Valid_BST(TreeNode* node)
	//{
	//	if (!node)
	//		return true;
	//	// 先递归访问至最深左节点
	//	if (!is_Valid_BST(node->left))
	//		return false;
	//	// 再判断是否升序
	//	if (prev  && node->val <= prev->val)
	//		return false;
	//	// 最后更新当前节点为前一个节点并访问右节点
	//	prev = node;
	//	return is_Valid_BST(node->right);
	//}
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
	TreeNode *T4 = new TreeNode(1);
	T4->left = new TreeNode(1);
	cout << s.isValidBST(T1) << endl;
	cout << s.isValidBST(T2) << endl;
	cout << s.isValidBST(T3) << endl;
	cout << s.isValidBST(T4) << endl;
	cout << s.isValidBST(NULL) << endl;
	system("pause");
	return 0;
}