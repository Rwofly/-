#include<iostream>
//��·�鲢_���� 
using namespace std;
struct List
{
	int data;
	struct List *pNext;
};
void show(List *L);
void init_list(List *&L);
void gui_bing(List *L1,List *L2,List *L3); 
int main()
{
	List *L1,*L2,*L3;
	init_list(L1);
	init_list(L2);
	L3=new List;
	L3->pNext=NULL;
	gui_bing(L1,L2,L3);
	cout<<"�鲢ǰ������"<<endl;
	show(L1);
	show(L2);
	cout<<"�鲢�������"<<endl;
	show(L3);
	return 0;
}
void init_list(List *&L)//β�巨 
{
	L=new List;
	L->pNext=NULL;
	List *val=L;
	int n,k;
	cout<<"����������Ԫ�ظ�����";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"�������"<<i+1<<"��Ԫ�ص�ֵ��";
		cin>>k;
		List *pNew=new List;
		pNew->data=k;
		val->pNext=pNew;
		pNew->pNext=NULL;
		val=pNew;
	}
	return;
}
void gui_bing(List *L1,List *L2,List *L3)
{
	List *l1,*l2,*val;
	l1=L1->pNext,l2=L2->pNext,val=L3;
	while(l1!=NULL&&l2!=NULL)
	{
		if(l1->data>l2->data)
		{
			List *pNew=new List;
			pNew->data=l2->data;
			l2=l2->pNext;
			val->pNext=pNew;
			pNew->pNext=NULL;
			val=pNew;
		}else
		{
			List *pNew=new List;
			pNew->data=l1->data;
			l1=l1->pNext;
			val->pNext=pNew;
			pNew->pNext=NULL;
			val=pNew;
		}
	}
	while(l1!=NULL)
	{
		    List *pNew=new List;
			pNew->data=l1->data;
			l1=l1->pNext;
			val->pNext=pNew;
			pNew->pNext=NULL;
			val=pNew;
	}
	while(l2!=NULL)
	{
		    List *pNew=new List;
			pNew->data=l2->data;
			l2=l2->pNext;
			val->pNext=pNew;
			pNew->pNext=NULL;
			val=pNew;
	}
	return;
}
void show(List *L)
{
	List *p=L->pNext;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->pNext;
	}
	cout<<endl;
}
