/*�ҳ����ȳ������е���λ��s1,s2����������˳���洢
˼·��
���������в���˳���洢ʱ��һ����������S����λ������S->data[S->length/2]
ֻ��Ҫ���������ж�·�鲢��һ��������S����ʵ����Ҫ���S��ȫ��Ԫ�أ���k��¼���鲢��Ԫ�صĸ���
��k=s1->lengthʱ���й鲢���Ǹ�Ԫ�ؾ�����λ�� 
*/
#include<iostream>
using namespace std;
#define Maxsize 5 
struct Num
{
	int *data;
	int length;
};
void init(Num *&num);
void show(Num *num);
int operation(Num *&num1,Num *&num2);
int main()
{
	Num *num1,*num2;
	init(num1);
	init(num2);
	cout<<"num1��Ԫ��Ϊ��"<<endl;
	show(num1);
	cout<<"num2��Ԫ��Ϊ��"<<endl;
	show(num2);
	int n=operation(num1,num2);
	cout<<"��˳������λ��Ϊ��"<<n<<endl; 
	return 0;
} 
void init(Num *&num)
{
	num=new Num;
	num->data=new int[Maxsize];
	num->length=0;
	cout<<"������"<<Maxsize<<"��˳���Ԫ��(��С��������)��";
	while(num->length<Maxsize)
	{
		cin>>num->data[num->length];
		num->length++;
	}
	return;
}
void show(Num *num)
{
	for(int i=0;i<num->length;i++)
	{
		cout<<num->data[i]<<" ";
	}
	cout<<endl;
	return;
}
int operation(Num *&num1,Num *&num2)
{
	int i=0,j=0,k=0;
	while(i<num1->length&&j<num2->length)//�������о�û��ɨ���� 
	{
		k++;//�鲢����һ
		if(num1->data[i]<num2->data[j])//�鲢��С��Ԫ�� 
		{
			if(k==num1->length)//����ǰ�鲢��Ԫ���������Ԫ�� 
			{
				return num1->data[i];
			}
			i++;
		}else//�鲢��С��Ԫ��num2->[j] 
		{
			if(k==num2->length)
			{
				return num2->data[j];
			}
			j++;
		} 
	}
}
