#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
const int maxn=2e5+10; //�ַ�����󳤶� 
char str[maxn]; //������ַ��� 
int sx[maxn]; //�ƶ��������x
int sy[maxn]; 
int l,r,mid; //mid��ʾ�����ֶγ��� 
int result; 
int x,y;

bool check(int len)
{
	
	for(int i=1;i+len-1<=n;i++) //���i �յ�mid+i-1  mid���� Ҫ���ĵ��ֶγ��Ȳ��� 
	{
		int tl=i; //������i 
	    int tr=i+len-1; //�Ҷ��յ�mid+i-1 
	    int movex=sx[tr]-sx[tl-1]; //���滻���� ɾȥ ��� ��ƫ���� 
		int movey=sy[tr]-sy[tl-1]; 
		int nowx=sx[n]-movex; //ԭ���������� ɾȥ  ���滻����� ���������� 
		int nowy=sy[n]-movey; 
		int dis=abs(x-nowx)+abs(y-nowy);// �������� �� Ŀ������ �����ƫ���� ����Ҫ�ı�Ĳ�������
		if(dis <= len && (len-dis)%2==0)
		{
			return true;
		} 
		 // (mid-dis) % 2 == 0 �Ǳ�֤ �ڻ��ж����ַ�������£���֤ �ܹ����� �� ��󵽴��յ�
		//��Ҫ��֤����ö�ٵ����������������Ҫ��֤�����滻��ȥ�����䳤�� len ��ż�Ժ��յ�������پ��� dis һ�£����ұ�֤len>=dis�� 
	}
	return false;	
}


int main()
{
	while(~scanf("%d",&n))
	{
		memset(str,' ',sizeof(str));
		memset(sx,0,sizeof(sx));
		memset(sy,0,sizeof(sy));
		scanf("%s",str); //str+1 ��& 
		scanf("%d%d",&x,&y); //Ŀ��λ�� 
		for(int i=1;i<=n;i++) //���ַ�������Ĳ�����ӳΪ����仯  //ǰ׺������ߵ���i�����λ��sx sy 
		{
			if(str[i-1]=='R')
			sx[i]=1;
			if(str[i-1]=='L') 
			sx[i]=-1;
			if(str[i-1]=='U')
			sy[i]=1;
			if(str[i-1]=='D')
			sy[i]=-1;
		}
		for(int i=1;i<=n;i++)
		{
			sx[i]=sx[i]+sx[i-1];
			sy[i]=sy[i]+sy[i-1];
		}
		l=0;
		r=n;
		result=-1;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(check(mid))
			{
				result=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		} 
		cout<<result<<endl;
	}
	return 0;
}
