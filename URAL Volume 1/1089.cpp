//#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char s[1001][9];
int ans=0;
int check(char a[],char b[])
{
    int sum=0;
    if(strlen(a)!=strlen(b)) return false;
    for(int i=0;i<strlen(a);i++)
        if(a[i]!=b[i]) sum++;
    if(sum<=1) return true;
    else return false;
}
int main()
{
    int n=0,l=0,i;
    char ch;
    char st[10];
    memset(s,0,sizeof(s));
    do{
      scanf("%s",s[++n]);
    }while(strcmp(s[n],"#")!=0);
    n--;
    gets(st);
    memset(st,0,sizeof(st));
    while(scanf("%c",&ch)!=EOF)
    {
        bool b=false;
        if(!isalpha(ch)){
          for(i=1;i<=n;i++)
           if(check(st,s[i])){
              printf("%s",s[i]);
              if(strcmp(st,s[i])!=0)ans++;
              b=true;
              break;
            }
          if(!b) printf("%s",st);
          printf("%c",ch);
          l=0;
          memset(st,0,sizeof(st));
        }
        else st[l++]=ch;
    }
    printf("%d",ans);
    return 0;
}