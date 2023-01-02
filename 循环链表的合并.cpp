#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};
void create_list(Node* pHead);//����ѭ������ 
void travel_list(Node* pHead);//����ѭ������ 
Node *add_list(Node* pHead1, Node* pHead2);//�ϲ�����ѭ������ 
int main()
{
	Node* pHead1 = new Node;
	Node* pHead2 = new Node;
	pHead1->next = pHead1;
	pHead2->next = pHead2;//ͷ���ָ���Լ� 
	create_list(pHead1);
	cout << "��һ�������Ԫ���У�" << endl;
	travel_list(pHead1);
	create_list(pHead2);
	cout << "�ڶ��������Ԫ���У�" << endl;
	travel_list(pHead2);
	Node* All_list;
	All_list=add_list(pHead1, pHead2);
	cout << "�ϲ��������Ϊ��" << endl;
	travel_list(All_list);
	return 0;
}
void create_list(Node* pHead)//β�巨����һ��ѭ������ 
{
	int n, val;
	Node* p = pHead;
	cout << "������Ҫ���ɽڵ�ĸ�����";
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		Node* pNew = new Node;
		cout << "������� " << i + 1 << " ���ڵ��ֵ��";
		cin >> val;
		pNew->data = val;
		pNew->next = pHead;
		p->next = pNew;
		p = pNew;
	}
	return;
}
void travel_list(Node* pHead)
{
	Node* p = pHead->next;
	while (p != pHead)//����ͨ������Ĳ�ͬ����ͷ���Ϊ�������� 
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return;
}
Node *add_list(Node* pHead1, Node* pHead2)
{
	/*�����Ϊ���õ�һ�����βָ��ָ��ڶ�����ĵ�һ���ڵ�
			  ���õڶ������βָ��ָ���һ�����ͷ��㣬Ȼ���ͷŵڶ������ͷ���
		*/
	Node* p1 = pHead1->next;
	Node* p2 = pHead2->next;
	while (p1->next != pHead1)//��p1��Ϊ��һ�������βָ�� 
	{
		p1 = p1->next;
	}
	while (p2->next != pHead2)//��p2��Ϊ�ڶ��������β��� 
	{
		p2 = p2->next;
	}
	p1->next = pHead2->next;//��һ�����βָ��ָ��ڶ�����ĵ�һ���ڵ�
	p2->next = pHead1;// �õڶ������βָ��ָ���һ�����ͷ���
	delete pHead2;//Ȼ���ͷŵڶ������ͷ���
	return pHead1;
}
