#include<iostream>
using namespace std;
/*��������� LA LB LC �ڵ����Ԫ�ص���ֵ���У�ʹ����LA�н�����
�������о�����������Ԫ�صĽ�㣬��û������ֵ��ͬ�ĵ�,���ͷ�LA�������ڵ㣬�㷨ʱ�临�Ӷ�Ϊ
O(m+n+p),��ÿ������ֻ����һ��*/ 
struct List
{
	int data;
	struct List *pNext;
};
void creat_list(List *&L);
void travel_list(List *L);
void operato(List *&LA,List *&LB,List *&LC);
int main()
{
	List *LA,*LB,*LC;
	creat_list(LA);
	creat_list(LB);
	creat_list(LC);
	cout<<"����LA��ֵΪ��"<<endl;
	travel_list(LA);
	cout<<"����LB��ֵΪ��"<<endl;
	travel_list(LB);
	cout<<"����LC��ֵΪ��"<<endl;
	travel_list(LC);
	operato(LA,LB,LC);
	cout<<"������LA �����ֵΪ��"<<endl;
	travel_list(LA);
	return 0;
}
void creat_list(List *&L)
{
	L=new List;
	L->pNext=NULL;
	List *val=L;
	int n;
	cout<<"����������Ԫ�ظ�����";
	cin>>n;
	int num;
	for(int i=0;i<n;i++)
	 {
	 	cout<<"�������"<<i+1<<"���ڵ��ֵ(�ɴ�С����):"; 
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
void operato(List *&LA,List *&LB,List *&LC)
{
	List *La=LA->pNext,*Lb=LB->pNext,*Lc=LC->pNext,*p,*q;
	LA->pNext=NULL;//��ʱLAΪ�½��������ͷ���
	p=LA;//pʼ��ָ��β���
	while(La!=NULL)//���ҹ����ڵ㲢����������LA 
	{
		while(Lb!=NULL&&La->data>Lb->data)
		{
			Lb=Lb->pNext;
		}
		while(Lc!=NULL&&La->data>Lc->data)
		{
			Lc=Lc->pNext;
		}
		if(Lb!=NULL&&Lc!=NULL&&Lb->data==La->data&&Lc->data==La->data)
		{
			//���La�ڵ��ǹ����ڵ㣬��La�ڵ���뵽���뵥����LA��
			p->pNext=La;
			p=La;
			La=La->pNext;
			
		}else//����ɾ�� La�ڵ� 
		{
			q=La;//���浱ǰLa�ڵ� 
			La=La->pNext;//La�ƶ�����һ�ڵ� 
			delete q;//�ͷŷǹ����ڵ� 
		}
	} 
	p->pNext=NULL;//β����pNext������Ϊ�� 
	return;
}
