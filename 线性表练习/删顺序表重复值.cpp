#include<iostream>
using namespace std;
/*��������L����С�������򣩣����һ����Ч�㷨��ɾ��ֵ���ظ��Ľڵ�
������
����Ϊ˳���������Ϊ��С���󣬹�ֻҪǰһ���ڵ�
���뱾�ڵ���ͬ�Ͳ����ظ��Ľڵ�*/ 
struct List
{
	int data;
	struct List *pNext;
};
void creat_list(List *&L);
void travel_list(List *L);
void operation(List *&L);
int main()
{
	List *L;
	creat_list(L);
	cout<<"����ǰ�����ֵΪ��"<<endl;
	travel_list(L);
	operation(L);
	cout<<"�����������ֵΪ��"<<endl;
	travel_list(L);
	return 0;
}
void creat_list(List *&L)
{
	L=new List;
	L->pNext=NULL;
	int n;
	cout<<"����������ĸ�����";
	cin>>n;
	List *val=L;
	int num;
	for(int i=0;i<n;i++)
	{
		cout<<"�������"<<i+1<<"���ڵ��ֵ��";
		cin>>num;
		List *pNew=new List;
		pNew->data=num;
		pNew->pNext=NULL;
		val->pNext=pNew;
		val=pNew;
	}
	return;
}
void travel_list(List *L)
{
	List *p=L->pNext;
	while(p!=NULL)
	{
	   cout<<p->data<<" ";
	   p=p->pNext; 
	}
	cout<<endl;
	return;
}
void operation(List *&L)
{
	List *p,*q,*t;
	p=L->pNext;
	q=p->pNext;//qָ��p����һ���ڵ� 
	while(q!=NULL)
	{
		if(p->data==q->data)
		{
			t=q;//tָ��q��ָ�Ľڵ�
			q=q->pNext;//q����һλ 
			p->pNext=q; 
			delete t;//�ͷ��ظ��ڵ� 
			 
		}else
		{
			p=q;
			q=q->pNext;//������ظ�����p��qͬʱ�����һλ 
		}
	}
	return;
}
