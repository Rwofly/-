#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};
void create_list(Node *pHead);//����ѭ������ 
void travel_list(Node* pHead);//����ѭ������ 
int main()
{
	Node* pHead=new Node;
	pHead->next=pHead;//ͷ���ָ���Լ� 
	create_list(pHead); 
	cout<<"�������Ԫ���У�"<<endl;
	travel_list(pHead);
	return 0;
}
void create_list(Node *pHead)//β�巨����һ��ѭ������ 
{
	int n,val;
	Node* p=pHead;
	cout<<"������Ҫ���ɽڵ�ĸ�����"; 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		Node* pNew=new Node;
		cout<<"������� "<<i+1<<" ���ڵ��ֵ��";
		cin>>val;
		pNew->data=val;
		pNew->next=pHead;
		p->next=pNew;
		p=pNew;
	}
	return;
}
void travel_list(Node* pHead)
{
	Node* p=pHead->next;
	while(p!=pHead)//����ͨ������Ĳ�ͬ����ͷ���Ϊ�������� 
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	return;
}
