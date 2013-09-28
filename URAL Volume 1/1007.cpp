#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
#include <iostream>
using namespace std;

#define maxn 2122
char s[maxn];
int n,m,x,y;
void first(){
	if (x%m==0){
		printf("%s\n",s);
		return; 
	}
    int xx,yy;
    for (int i=0; i<strlen(s); i++){
    	xx=x; yy=y;
    	if (s[i]=='1'){
   	        xx-=i+1;
   	        yy+=i+1;
	    }
    	if (xx%m==0){
    		if (s[i]=='1') s[i]='0';
    		else s[i]='1';
	    	printf("%s\n",s);
	    	return;
	    }
    }
	return;
}
void second(){
	int xx,yy;
	for (int i=0; i<=strlen(s); i++){
		xx=x; yy=y;
		for (int j=i; j<strlen(s); j++)
		    if (s[j]=='1') xx++;
		    else yy++;
        if ((xx+i+1)%m==0){
        	for (int j=0; j<=i-1; j++) printf("%c",s[j]);
        	printf("1");
        	for (int j=i; j<strlen(s); j++) printf("%c",s[j]);
        	printf("\n");
        	return;
        }
        if (xx%m==0){
        	for (int j=0; j<=i-1; j++) printf("%c",s[j]);
        	printf("0");
        	for (int j=i; j<strlen(s); j++) printf("%c",s[j]);
        	printf("\n");
        	return;
        }
	}
 
	return;
}
void third(){
	int xx,yy;
	for (int i=0; i<strlen(s); i++){
		xx=x; yy=y;
		for (int j=i+1; j<strlen(s); j++)
		    if (s[j]=='1') xx--;
		    else yy--;
        if (s[i]=='1') xx-=i+1;
        else yy-=i+1;
        if (xx%m==0){
        	for (int j=0; j<=i-1; j++) printf("%c",s[j]);
        	for (int j=i+1; j<strlen(s); j++) printf("%c",s[j]);
        	printf("\n");
        	return;
        }
	}
	return;
}
int main(){
	scanf("%d",&n); getchar(); m=n+1;
	while (scanf("%s",&s)!=EOF){
		x=y=0;
		for (int i=0; i<strlen(s); i++)
		    if (s[i]=='1') x+=i+1;
		    else y+=i+1;
		if (strlen(s)==n) first();
		if (strlen(s)<n) second();
		if (strlen(s)>n) third(); 
	}
	return 0;
}