#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};
void create_list(Node* pHead);//����������
void travel_list(Node* pHead);//����������
Node* add_list(Node* pHead1, Node* pHead2);//�ϲ�����������
int main()
{
	Node* pHead1 = new Node;
	Node* pHead2 = new Node;
	pHead1->next = NULL;
	pHead2->next = NULL;
	create_list(pHead1);
	cout << "��һ�������Ԫ���У�" << endl;
	travel_list(pHead1);
	create_list(pHead2);
	cout << "�ڶ��������Ԫ���У�" << endl;
	travel_list(pHead2);
	Node* all_list = new Node;
	all_list=add_list(pHead1, pHead2);
	cout << "�ϲ��������ֵΪ��" << endl;
	travel_list(all_list);
	return 0;
}
void create_list(Node* pHead)//β�巨����������
{
	int n, val;
	Node* p = pHead;
	cout << "������Ҫ���ɽڵ�ĸ�����";
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		Node* pNew = new Node;
		cout << "����� " << i + 1 << " ���ڵ��ֵ��";
		cin >> val;
		pNew->data = val;
		p->next = pNew;
		pNew->next = NULL;
		p = pNew;
	}
	return;
}
void travel_list(Node* pHead)
{
	Node* p = pHead->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return;
}
Node* add_list(Node* pHead1, Node* pHead2)
{
	//���������������pHead1��β���ָ��pHead2��ͷ��㣬���ͷ�pHead2��
	Node* p1 = pHead1->next;
	Node* p2 = pHead2->next;
	while (p1 ->next!= NULL)//��p1ָ������pHead1��β���
	{
		p1 = p1->next;
	}
	p1->next = pHead2->next;
	delete pHead2;
	return pHead1;
}