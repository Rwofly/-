#include<iostream>//����˼·�뵥������ͬ,�����ɡ����������롢ɾ������ �� 
#include<stdlib.h> 
using namespace std;
struct Node
{
	int data;
	struct Node *pre,*next;
};
void creat_list(Node* pHead);//����˫������ 
void travel_list(Node* pHead);//���������˫������ 
void insert_list(Node* pHead,int pos,int n);//˫������Ĳ��� 
void delete_list(Node* pHead,int pos);//˫�������ɾ�� 
void test_travel(Node* pHead);//����˫����������pre�ڵ������������ 
int main()
{
	Node* pHead=new Node;
	pHead->next=NULL;
	pHead->pre=NULL;
	creat_list(pHead);
	cout<<"˫�������Ԫ���У�"<<endl;
	travel_list(pHead);
	int pos,n;
	cout<<"���������Ԫ�ص�λ�ã�";
	cin>>pos;
	cout<<"���������Ԫ�ص�ֵ��";
	cin>>n;
	insert_list(pHead,pos,n);
	cout<<"����Ԫ�غ��ֵ����Ϊ��"<<endl;
	travel_list(pHead);
	cout<<"������ɾ��Ԫ�ص�λ�ã�";
	cin>>pos;
	delete_list(pHead,pos);
	cout<<"ɾ��һ��Ԫ�غ�����Ϊ��"<<endl;
	travel_list(pHead);
	cout<<"�������Ϊ��"<<endl;
	test_travel(pHead);
	return 0;
}
void creat_list(Node* pHead)
{
	int n,val;
	Node* p=pHead;
	cout<<"��������������ĸ�����";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		Node* pNew=new Node;
		cout<<"������� "<<i+1<<" �������ֵ��";
		cin>>val;
		pNew->data=val;
		p->next=pNew;
		pNew->pre=p;
		pNew->next=NULL;
		p=pNew; 
	}
	return;
}
void travel_list(Node* pHead)//������������������ͬ 
{
	Node* p=pHead->next;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
	return;
}
void insert_list(Node* pHead,int pos,int n)
{
	Node* p=pHead;
	int i=0;
	while(p!=NULL&&i<pos-1)//�жϲ��ָ�������һ�� 
	{
		i++;
		p=p->next;
	}
	if(p==NULL||i>pos-1)
	{
		cout<<"���ڲ��뷶Χ֮��,�˳�����";
		exit(-1); 
	} 
	Node* pNew=new Node;
	pNew->data=n;
	pNew->next=p->next;//�½ڵ�ָ����һ���ڵ� 
	p->next->pre=pNew; //��һ���ڵ���ָ���½ڵ� 
	p->next=pNew;//ǰһ���ڵ�ָ���½ڵ� 
	pNew->pre=p;//�½ڵ�ָ��ǰһ���ڵ�    һ���Ĳ� 
	return;
}
void delete_list(Node* pHead,int pos)
{
	Node* p=pHead;
	int i=0;
	while(p->next!=NULL&&i<pos-1)//�жϸ���������ͬ 
	{
		i++;
		p=p->next;
	}
	if(p->next==NULL&&i>pos-1)
	{
		cout<<"��������Χ���˳�����";
		exit(-1);
	}
	p=p->next;//��Ҫ ����p�ƶ���ɾ��λ�� 
	p->pre->next=p->next;//p��ǰһ���ڵ�ָ��p�ĺ�һ���ڵ� 
	p->next->pre=p->pre;//p�ĺ�һ���ڵ�ָ��ǰһ���ڵ� 
	delete p;//�ͷ�p�ڵ���ڴ� 
	return;
}
void test_travel(Node* pHead)
{
	Node* p=pHead->next;
	while(p->next!=NULL)//��p�ƶ���β��� 
	{
		p=p->next;
	}
	while(p->pre!=NULL)
	{
		cout<<p->data<<" ";
		p=p->pre;
	}
	cout<<endl;
	return;
} 
/*������������˫��ѭ���������˸��Ƶģ�
���������ˣ��������˹�����Ҳ�������Ͳ����ˡ������������������һ���ˣ�
�ܹ������������У�����һ��
2023 01 02 */ 
