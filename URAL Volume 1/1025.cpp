#include <stdio.h>
#define maxn 102
int a[maxn], k, i, j, n, s;
void qs(int s, int t);
int main()
{
	scanf("%d", &n);
	for(i=1;i<=n;++i)
		scanf("%d", &a[i]);

	qs(1, n);

	s=0;
	for(i=1;i<=n/2+1;++i)
		s+=a[i]/2+1;

	printf("%d\n", s);
	return 0;
}

void qs(int s, int t)
{
	int i=s, j=t, x=a[(s+t)/2], tmp;
	while(i<=j){
		while(a[i]<x) ++i;
		while(x<a[j]) --j;
		if(i<=j){
			tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
			++i;
			--j;
		}
	}
	if(s<j)
		qs(s, j);
	if(i<t)
		qs(i, t);
}