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
		// 正常删除节点的方法为:将上一节点next所存地址更换为下一节点的地址,
		// 本函数参数node为所需删除节点的地址,故无法改变更改上一节点(中next)的内容
		// 故本函数为将node地址所指向的节点内容整个替换为下一个节点的节点内容
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
