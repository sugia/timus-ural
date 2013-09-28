//#include "stdafx.h"
#include <cstdio>
#include <cstring>
 
int s[5][5],tmp[5][5],dir[5][2],a[5],ans,b[5];
char ch[5][5];
bool tt=false;
 
inline void Change(int x,int y){
	tmp[x][y]^=1;
	for (int i=1;i<=4;i++){
		int fx=x+dir[i][0],fy=y+dir[i][1];
		if (fx>0 && fx<=4 && fy>0 && fy<=4)
			tmp[fx][fy]^=1;
	}
}
 
void Search(int k){
	if (k>4){
		for (int i=1;i<=4;i++)
			memcpy(tmp,s,sizeof tmp);
		memcpy(a,b,sizeof a);
		int sum=0,j;
		for (int i=1;i<=4;i++){
			j=0;
			while (a[i]){
				j++;
				if (a[i]&1){
					sum++;
					Change(i,j);
				}
				a[i]/=2;
			}
		}
		for (int i=1;i<=4;i++)
		for (int j=1;j<=4;j++)
		if (tmp[i][j]!=tmp[1][1])	return;
		tt=true;
		if (sum<ans)	ans=sum;
		return;
	}
	for (int i=0;i<1<<4;i++){
		b[k]=i;
		Search(k+1);
	}
}
 
int main(){
//	freopen("s.in","r",stdin);
//	freopen("s.out","w",stdout);
 
	dir[1][0]=0,dir[2][0]=0,dir[3][0]=1,dir[4][0]=-1;
	dir[1][1]=1,dir[2][1]=-1,dir[3][1]=0,dir[4][1]=0;
 
	for (int i=1;i<=4;i++)
		scanf("%s",&ch[i]);
	for (int i=1;i<=4;i++)
	for (int j=1;j<=4;j++)
		s[i][j]=(ch[i][j-1]=='b');
 
	ans=2134000000;
	Search(1);
 
	if (tt)	printf("%d\n",ans);
	else	printf("Impossible\n");
 
	return 0;
}