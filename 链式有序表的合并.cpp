#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
void creat_list(Node*);//β�巨������������
void travel_list(Node*);//�������������
void add_list(Node*, Node*,Node*);//������ʽ�����ĺϲ�
int main()
{
	Node* pHead1 =new Node;
	Node* pHead2 =new Node;
	Node* pHead3 = new Node;
	pHead1->next = NULL;
	pHead2->next = NULL;
	pHead3->next = NULL;
	creat_list(pHead1);
	creat_list(pHead2);
	cout << "��һ������Ԫ���У�" << endl;
	travel_list(pHead1);
	cout << "�ڶ��������Ԫ���У�" << endl;
	travel_list(pHead2);
	add_list(pHead1, pHead2, pHead3);
	cout << "�ϲ��������Ԫ��Ϊ��" << endl;
	travel_list(pHead3);
	return 0;
}
void creat_list(Node* pHead)
{
	int n, m;
	Node* val;
	val = pHead;
	cout << "��������������ĸ�����";
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cout << "������� " << i + 1 << " ���ڵ��ֵ(��С��������)��";
		cin >> m;
		Node* pNew = new Node;
		if (pNew == NULL)
		{
			cout << "�ڴ����ʧ�ܣ�";
			exit(-1);
		}
		pNew->data = m;
		pNew->next = NULL;
		val->next = pNew;
		val = pNew;
	}
	return;
}
void travel_list(Node* pHead)
{
	Node* p=pHead->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return;
}
void add_list(Node* pHead1, Node* pHead2,Node* pHead3)//��pHead1��pHead2�ڵ����pHead3�ڵ�֮��
{
	Node* p1, * p2, * p3;
	p1 = pHead1->next, p2 = pHead2->next, p3 = pHead3;
	while (p1 && p2)//��p1��p2����ָ��β���ʱ����ѭ��
	{
		if (p1->data <= p2->data)
		{
			p3->next = p1;//��p1��ָ�ڵ����p3��ָ�ڵ�֮��
			p3 = p1;//p3ָ��p1,�൱��β�巨��������
			p1 = p1->next;//p1ָ����һ�ڵ�
		}
		else
		{
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
	}
	p3->next = p1 > p2 ? p1 : p2;//��ʣ��ķǿձ���뵽p3��ָ�Ľڵ����
	delete pHead1;//�ͷ�pHead1,pHead2 �Ŀռ�
	delete pHead2;
	return;
}