#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
	int data;//������
	struct Node* pNext;//ָ����
}NODE,*PNODE;
PNODE create_list();
void travel_list(PNODE pHead);
bool is_empty(PNODE pHead);//�Ƿ�Ϊ��
int length_list(PNODE);//�ڵ㳤��
bool insert_list(PNODE,int,int);//����ڵ�
bool delete_list(PNODE,int);//ɾ���ڵ�
void soert_list(PNODE, int);//����

int main(void)
{
	PNODE pHead = NULL;
	pHead = create_list();
	travel_list(pHead);
	if (is_empty(pHead))
	{
		printf("����Ϊ��\n");
	}
	else
	{
		printf("����Ϊ����\n");
	}
	int len = length_list(pHead);
	printf("��������%d\n", len);
	soert_list(pHead, len);
	printf("�����ڵ��ǣ�\n");
	travel_list(pHead);
	insert_list(pHead, 4, 33);
	printf("����һ�������Ϊ��\n");
	travel_list(pHead, len);
	delete_list(pHead,4);
	printf("ɾ��һ�������Ϊ��\n");
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
		printf("����ʧ�ܣ�������ֹ��");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	printf("����������Ҫ��������ĸ�����");
	scanf_s("%d", &len);
	for (i = 0;i < len;i++)
	{
		printf("�������%d���ڵ��ֵ��", i + 1);
		scanf_s("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
		{
			printf("����ʧ�ܣ�������ֹ��");
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
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
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
bool insert_list(PNODE pHead, int pos, int val)//����һ��Ԫ��
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
		printf("��̬�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	pNew->data = val;
	pNew->pNext = p->pNext;
	p->pNext = pNew;
	return true;
}
bool delete_list(PNODE pHead, int pos)//ɾ��һ��Ԫ��
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
	free(q);
	return true;
}
	