#include<iostream>//���Ա�ĺϲ���һ�㼯�ϵĲ������⡣
using namespace std;
#define Max 20
int get_length(int*);//�����Ա��Ԫ�ظ���
int add_list(int*, int*, int, int);//���������Ϻϲ�
int main()
{
	int num1[Max] = { 7,5,3,11,15,16 };
	int num2[Max] = { 2,6,3,9,11 };
	int len1, len2;
	len1 = get_length(num1);
	len2 = get_length(num2);
	len1=add_list(num1, num2, len1, len2);
	cout << "�ϲ���Ľ��Ϊ��" << endl;
	for (int i = 0;i < len1;i++)
	{
		cout << num1[i] << " ";
	}
	return 0;
}
int get_length(int* p)
{
	int len = 0;
	int* pl = p;
	while (*pl != 0)
	{
		pl++;
		len++;
	}
	return len;
}
int add_list(int* num1, int* num2, int len1, int len2)
{
	int count = 0;
	for (int i = 0;i < len2;i++)
	{
		for (int j = 0;j < len1;j++)
		{
			if (num2[i] == num1[j])
			{
				count++;
			}
		}
		if (count == 0)
		{
			len1++;
			num1[len1 - 1] = num2[i];
		}
		else
		{
			count = 0;
		}
	}
	return len1;
}