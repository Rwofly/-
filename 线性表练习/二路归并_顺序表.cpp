#include<iostream>
/*�����Ķ�·�鲢�㷨 ������˳���ķ���ʵ�� 
������Ƿֱ�ɨ��LA��LB��������������������û�б�����ʱѭ����
�Ƚ�LA��LB�ĵ�ǰԪ�أ������н�С��Ԫ�ط���LC�У��ٴӽ�СԪ����
�ڵ��������ȡ��һ��Ԫ�ء��ظ���һ���̣�ֱ��LA��LB������ϣ�
���δ�����������������µ�Ԫ�ط���LC�С�*/
using namespace std;
#define Maxsize 20
struct Num
{
	int length;
	int *numb;
};
void show(Num *num);
void init_Num(Num *num);//��ʼ��
void gui_bing(Num *num1,Num *num2,Num *num3);
int main()
{
	Num num1,num2,num3;
	init_Num(&num1);
	init_Num(&num2);
	num3.length=num1.length+num2.length;
	num3.numb=new int[num3.length];
	gui_bing(&num1,&num2,&num3);
	cout<<"�鲢�����Ϊ��"<<endl;
	show(&num3);
	return 0;
} 
void init_Num(Num *num)
{
	cout<<"���������鳤�ȣ�";
	cin>>num->length;
	num->numb=new int[num->length];
	cout<<"����������Ԫ��(��С����)��";
	for(int i=0;i<num->length;i++)
	{
		cin>>num->numb[i];
	}
	return;
}
void show(Num *num)
{
	for(int i=0;i<num->length;i++)
	{
		cout<<num->numb[i]<<" ";
	}
	cout<<endl;
	return;
}
void gui_bing(Num *num1,Num *num2,Num *num3)
{
	 int i=0,j=0,k=0;
	 while(i<num1->length&&j<num2->length)
	 {
	 	if(num1->numb[i]>num2->numb[j])
	 	{
	 	    num3->numb[k]=num2->numb[j];
			 k++;
			 j++; 
		}else
		{
			num3->numb[k]=num1->numb[i];
			k++;
			i++;
		}
	 }
	 while(i<num1->length)//��num1δ������ 
	 {
	    num3->numb[k]=num1->numb[i];
	 	k++;
	 	i++;
	 }
	 while(j<num2->length)//��num2δ������ 
	 {
	    num3->numb[k]=num2->numb[j];
	 	k++;
	 	j++;
	 }
	return;
}
