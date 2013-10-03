#include<stdio.h>
#include<string.h>
#include<algorithm>
const int INF  = 2147483647;
int n,ans[1001];
struct hero{
	int num,value;
};
hero a[1001];
void print(int x)
{
	for(int i=1;i<=x;i++)
	{
		printf("%d",ans[i]);
		for(int j=1;j<=ans[i];j++)
		printf(" %d",a[j].num);
		printf("\n");
	}
}
bool cmp(const hero& a,const hero& b)
{
	return a.value<b.value;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&a[i].value);a[i].num=i;}
	std::sort(a+1,a+n+1,cmp);
	a[n+1].value=INF;
	int now=0;
	for(int i=1;i<=n;i++)
		if(i+1<a[i+1].value&&i>=a[i].value)ans[++now]=i;
	printf("%d\n",now);
	print(now);
	return 0;
}
