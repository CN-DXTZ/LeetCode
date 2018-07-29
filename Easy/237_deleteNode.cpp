#include<iostream>
#include<string> 
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
	void deleteNode(ListNode* node)
	{
		// 正常方法为将上一个节点next所存地址更换为下一个节点的地址,不过受该函数参数限制
		// node为所需删除的节点地址,即上一个节点next所保存的地址，但无法更改上一个节点next的内容
		// 故删除该节点为将node地址所指向的节点内容替换为下一个节点的节点内容
		//auto a = node->next;
		//auto b = *node;
		//auto c = *(node->next);
		//auto d = (*node).next;
		*node = *(node->next);
	}
} s;

ListNode *l1 = new ListNode(4);
int main()
{
	l1->next = new ListNode(5);
	l1->next->next = new ListNode(1);
	l1->next->next->next = new ListNode(9);
	s.deleteNode(l1->next->next);
	s.deleteNode(l1->next);

	while (l1)
	{
		cout << l1->val << endl;
		l1 = l1->next;
	}
	system("pause");
	return 0;
}
