#include <cstdio>
int n;
int main(){
	scanf("%d", &n);
	if(n==2){
		printf("2\n");
		printf("2 2\n");
		return 0;
	}
	printf("%d\n", n+n-4);
	printf("2");
	for(int i=3;i<n;++i) printf(" %d", i);
	for(int i=n-1;i>1;--i) printf(" %d", i);
	printf("\n");
	return 0;
}