#include<iostream> 
#include<stdlib.h>
using namespace std;
typedef struct Node
{
	int data;//������ 
	struct Node* pNext;//ָ���� 
}NODE,*PNODE;
PNODE create_list();//�������� ������ʹ��β�巨 
void travel_list(PNODE pHead);//������������� 
bool is_empty(PNODE pHead);//�ж������Ƿ�Ϊ�� 
int length_list(PNODE);//������ĳ��� 
bool insert_list(PNODE,int,int);//�������в���һ��Ԫ�� 
bool delete_list(PNODE,int);//��������ɾ��һ��Ԫ�� 
void soert_list(PNODE, int);//������Ԫ�ص����� 

int main(void)
{
	PNODE pHead = NULL;
	pHead = create_list();
	travel_list(pHead);
	if (is_empty(pHead))
	{
		cout<<"����Ϊ�ա�"<<endl; 
	}
	else
	{
		cout<<"����Ϊ�ǿա�"<<endl;
	}
	int len = length_list(pHead);
	cout<<"�������ǣ�"<<len;
	soert_list(pHead, len);
    cout<<"����������Ϊ��"<<endl;
	travel_list(pHead);
	int pos,val;
	cout<<"���������ڵ��λ�ã�";
	cin>>pos;
	cout<<"������Ҫ�����ֵ��";
	cin>>val; 
	insert_list(pHead, pos, val);
	cout<<"����һ��Ԫ�غ�����Ϊ��"<<endl; 
	travel_list(pHead);
	cout<<"������Ҫɾ���ڵ��λ�ã�";
	cin>>pos;
	delete_list(pHead,pos);
	cout<<"ɾ���ڵ�������Ϊ��"<<endl; 
	travel_list(pHead);
	return 0;
}
PNODE create_list()
{
	int len, i;
	int val;
	PNODE pHead=(PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		cout<<"�ڴ����ʧ�ܣ��˳�����";
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	cout<<"������Ҫ���ɽڵ�ĳ��ȣ�";
	cin>>len;
	for (i = 0;i < len;i++)
	{
		cout<<"������� "<<i+1<<" ���ڵ��ֵ��";
		cin>>val; 
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
		{
			cout<<"�ڴ����ʧ�ܣ��˳�����";
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}
void travel_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	while (p!= NULL)
	{
		cout<<p->data<<" ";
		p = p->pNext;
	}
	cout<<endl;
	return;
}
bool is_empty(PNODE pHead)
{
	if (NULL == pHead->pNext)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int length_list(PNODE pHead)
{
	int count = 0;
	PNODE p = pHead->pNext;
	while (p != NULL)
	{
		count++;
		p = p->pNext;
	}
	return count;
}
void soert_list(PNODE pHead,int len)
{
	int i, j, t;
	PNODE p, q;
	for (i = 0, p = pHead->pNext;i < len - 1;i++, p = p->pNext)
	{
		for (j = i + 1, q = p->pNext;j < len;j++, q = q->pNext)
		{
			if (p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
	return;
}
bool insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;
	while (NULL != p && i < pos - 1)
	{
		p = p->pNext;
		i++;
	}
	if (i > pos - 1 || NULL == p)
	{
		return false;
	}
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		cout<<"�ڴ����ʧ�ܣ��˳�����";
		exit(-1);
	}
	pNew->data = val;
	pNew->pNext = p->pNext;
	p->pNext = pNew;
	return true;
}
bool delete_list(PNODE pHead, int pos)
{
	int i = 0;
	PNODE p = pHead;
	while (NULL != p->pNext && i < pos - 1)
	{
		p = p->pNext;
		i++;
	}
	if (i > pos - 1 || NULL == p->pNext)
	{
		return false;
	}
	PNODE q = p->pNext;
	p->pNext = q->pNext;
	delete q;//�ͷű�ɾ���ڵ���ڴ� 
	return true;
}
	
