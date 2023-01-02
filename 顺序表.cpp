#include<iostream>
using namespace std;
int Maxsize=100;
int *create_list(int n);
int menu();
void insert_list(int &n,int *p);
void delete_list(int &n,int *p);
int main()
{
	int n,*p;
	cout<<"����Ҫ������ٸ�����:"<<endl;
	cin>>n;
	while(n>Maxsize)
	{
		cout<<"�������������룡"<<endl;
		cout<<"����Ҫ������ٸ�����:"<<endl;
	    cin>>n;
	}
	p=create_list(n);
	int numb=menu(); 
    while(numb)
    {
    	switch(numb)
    	{
    		case 1:insert_list(n,p);break;
    		case 2:delete_list(n,p);break;
    		case 3:delete [] p;return 0;
		}
		cout<<endl;
		numb=menu();
	}
	return 0;
}
int *create_list(int n)
{
	int *p;
	p=new int [Maxsize];
	if(!p)
	{
		cout<<"�ڴ����ʧ�ܣ�";
	}
	cout<<"������������������֣�"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	return p;
}
int menu()
{
	int k;
	cout<<"--------------------------"<<endl;
	cout<<"1.����һ�����֡�"<<endl;
	cout<<"2.ɾ��һ�����֡�"<<endl;
	cout<<"3.�˳���"<<endl;
	cout<<"--------------------------"<<endl;
	cout<<"������ѡ�"<<endl;
	cin>>k;
	return k;
}
void insert_list(int &n,int *p)
{
	int k,d;
	cout<<"������ʲôλ�ò���һ�����֣�"<<endl;
	cin>>k;
	while(k>n||k<1)
	{
		cout<<"�������������룡"<<endl;
		cout<<"������ʲôλ�ò���һ�����֣�"<<endl;
	    cin>>k;
	}
	cout<<"�����������������֣�"<<endl;
	cin>>d;
	for(int i=n-1;i>=k-1;i--)
	{
		p[i+1]=p[i];
	}
	n=n+1;//����һ 
	p[k-1]=d;
	cout<<"���������Ϊ��"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<p[i]<<" ";
	}
	return;
}
void delete_list(int &n,int *p)
{
	int k;
	cout<<"������ʲôλ��ɾ��һ�����֣�"<<endl;
	cin>>k;
	while(k>n||k<1)
	{
		cout<<"�����������룡"<<endl;
		cout<<"������ʲôλ��ɾ��һ�����֣�"<<endl;
	    cin>>k;
	}
	for(int i=k;i<n;i++)
	{
	  p[i-1]=p[i]; 
	}
	n=n-1;//����һ 
	cout<<"ɾ���������Ϊ��"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<p[i]<<" ";
	}
	return;
}

