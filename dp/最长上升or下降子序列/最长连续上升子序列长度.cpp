/*���еĲ��������������ٻ������������е�����������г���
  ���еĲ��½����������ٻ������������е���½������г���
*/
//������������� 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define ll long long 
using namespace std;
const int N=1e5;
int n;
int a[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	vector<int>f(n,1); //��iΪ��β����������������г��� 
	int res=1; //����������������������г��� ����Ϊ1 
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[i-1]) //����>ǰ�� 
		  f[i]=f[i-1]+1;  //��iΪ��β�������г���+1 
		if(f[i]>res) //�и����������� 
		  res=f[i];  //����res 
		
	}
	cout<<res<<endl; //��� 
	return 0;
}
 

 
