#include<iostream>
/*
�Ե������׽ڵ�ֵxΪ��׼���õ�����ָ�Ϊ�����֣�ʹ����С��x�Ľڵ�����
���ڻ����x�Ľڵ�֮ǰ 
*/ 
using namespace std;
struct List
{
	int data;
	struct List *pNext;
};
void init_list(List *&L);//��ʼ��������
void create_list(List *&L);//����������,ʹ��β�巨���� 
void travel_list(List *L);//���������� 
bool if_empty(List *L);//�ж������Ƿ�Ϊ�� 
void destory_list(List *&L);//���ٵ����� 
void operation(List *&L,List *&A);
int main()
{
	List *L=NULL;
	init_list(L);
	create_list(L);
	 cout<<"��������Ϊ��"<<endl;
	 travel_list(L);
	 List *A=NULL;
	 operation(L,A);
	 cout<<"�������������Ϊ��"<<endl;
	 travel_list(A);
	 destory_list(L);
	 destory_list(A);
	return 0;
}
void init_list(List *&L)
{
	L=new List;
	L->pNext=NULL;
	return;
}
void create_list(List *&L)
{
	int n;
	cout<<"���������ɽڵ�ĸ�����";
	cin>>n;
	List *val=L;
	int data;
	for(int i=0;i<n;i++)
	{
		cout<<"�������"<<i+1<<"���ڵ��ֵ:";
		cin>>data;
		List *pNew=new List;
		pNew->data=data;
		pNew->pNext=NULL;
		val->pNext=pNew;
		val=pNew; 
	}
	return;
}
bool if_empty(List *L)
{
	if(L->pNext==NULL)
	{
		return true;
	}
	return false;
}
void travel_list(List *L)
{
	if(if_empty(L))
	{
		cout<<"����Ϊ�գ�"<<endl;
		return;
	}
	List *p=L->pNext;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->pNext;
	}
	cout<<endl;
	return;
}
void destory_list(List *&L)
{
	List *p=L->pNext;
	List *val;
	while(p!=NULL)
	{
		val=p;
		p=p->pNext;
		delete val;
	}
	delete L;
	return;
}
void operation(List *&L,List *&A)
{
	init_list(A);//��ʼ���½ڵ�A 
	List *pNew=new List;
	pNew->data=L->pNext->data;
	int x=pNew->data;//��¼����L���׽ڵ��ֵ 
	A->pNext=pNew;//�½ڵ�A���׽ڵ�Ϊ�ڵ�L���׽ڵ� 
	pNew->pNext=NULL;
	List *p=L->pNext->pNext;//pָ��L����ĵڶ����ڵ� 
	List *val=A;List *val2=A->pNext;List *val3=A->pNext;
	while(p!=NULL)
	{
		if(p->data<x)//����ڵ�Ԫ�ص�ֵС������L�׽ڵ��ֵ������ǰ�ƶ� 
		{
			//��������A���½ڵ�
			List *pNew=new List; 
			pNew->data=p->data;
			//���½ڵ��������Bԭʼ�׽ڵ��ǰ�� ������ԭʼ�׽ڵ�֮ǰʹ��β�巨 
			val->pNext=pNew;
			pNew->pNext=val2;
			val=pNew;
		}else
		{
			 //��������A���½ڵ�
			List *pNew=new List;
			pNew->data=p->data;
			pNew->pNext=NULL;
			//���½���β�巨��������A���� 
			val3->pNext=pNew;
			val3=pNew;
		}
		p=p->pNext;
	}
	return;
}
