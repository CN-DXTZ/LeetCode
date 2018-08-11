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
	// ����: ȷ��ÿ���ڵ�ļ�ֵ�ڵ㲢����
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
	// ��һ: ˳�����ѱ���ӦΪ��������
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
	//	// �ȵݹ������������ڵ�
	//	if (!is_Valid_BST(node->left))
	//		return false;
	//	// ���ж��Ƿ�����
	//	if (prev  && node->val <= prev->val)
	//		return false;
	//	// �����µ�ǰ�ڵ�Ϊǰһ���ڵ㲢�����ҽڵ�
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