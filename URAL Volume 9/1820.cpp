#include <stdio.h>
int main(){
    int n, k;
	scanf("%d%d", &n, &k);
	printf("%d\n", k>=n?2:2*n%k?2*n/k+1:2*n/k);
	return 0;
}