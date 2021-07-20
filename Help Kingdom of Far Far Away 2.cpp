
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<stdlib.h>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
    char s[105];
    int tag=0,pos=-1,len,i;
    scanf("%s",s);
    len=strlen(s);
    if(s[0]=='-')
    {
        for(i=1;s[i];i++)
        {
            if(s[i]=='.')
            {
                pos=i;
                break;
            }
        }
        if(pos==-1)
        {
            s[i]='.';
            pos=i;
            s[i+1]='0';
            s[i+2]='0';
            s[i+3]='\0';
            len+=3;
        }
        else if(len-pos<3)
        {
            len=pos+3;
            i=pos+1;
            int flag=0;
            while(i<len)
            {
                if(s[i]=='\0'||flag)
                {
                    s[i]='0';
                    flag=1;
                }
                i++;
            }
            s[i]='\0';
        }
        else
        {
            len=pos+3;
            s[len]='\0';
        }
        printf("($");
        for(i=1;s[i];i++)
        {
            if(abs(pos-i)%3==0&&i<pos&&i!=1)
                printf(",");
            printf("%c",s[i]);
        }
        printf(")\n");
    }
    else
    {
        for(i=0;s[i];i++)
        {
            if(s[i]=='.')
            {
                pos=i;
                break;
            }
        }
        if(pos==-1)
        {
            s[i]='.';
            pos=i;
            s[i+1]='0';
            s[i+2]='0';
            s[i+3]='\0';
            len+=3;
        }
        else if(len-pos<3)
        {
            len=pos+3;
            i=pos+1;
            int flag=0;
            while(i<len)
            {
                if(s[i]=='\0'||flag)
                {
                    s[i]='0';
                    flag=1;
                }
                i++;
            }
            s[i]='\0';
        }
        else
        {
            len=pos+3;
            s[len]='\0';
        }
        printf("$");
        for(i=0;s[i];i++)
        {
            if(abs(pos-i)%3==0&&i<pos&&i!=0)
                printf(",");
            printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}


