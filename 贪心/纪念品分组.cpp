//̰�� +���� 
//���ĺ�����˵�һ�� �ﵽ���ٷ��� �����۸�����������Ϊһ��
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int w;
	cin>>w;
	int n;
	cin>>n;
	int a[32000];
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1); //��С�������� 
	int ans=0;
	int l=1;
	int r=n;
	while(l<=r)
	{
		if((a[l]+a[r])<=w&&l!=r)
		{
			ans++;
			l++;
			r--;
		}
		else
		{
			ans++;
			r--;
		}
	}
	cout<<ans<<endl;
	
	return 0;
} 
