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
		// ����ɾ���ڵ�ķ���Ϊ:����һ�ڵ�next�����ַ����Ϊ��һ�ڵ�ĵ�ַ,
		// ����������nodeΪ����ɾ���ڵ�ĵ�ַ,���޷��ı������һ�ڵ�(��next)������
		// �ʱ�����Ϊ��node��ַ��ָ��Ľڵ����������滻Ϊ��һ���ڵ�Ľڵ�����
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
