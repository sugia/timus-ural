#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	int a[n+1], b[n+1];
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	memset(b, 0, sizeof(b));
	int min = a[1], minindex = 1;
	for (int i = 2; i <= n; ++i){
		++b[minindex];
		++b[i];
		if (a[i] < min){
			min = a[i];
			minindex = i;
		}
	}
	int maxindex = 1, max = b[1];
	for (int i = 2; i <= n; ++i)
		if (b[i] > max){
			max = b[i];
			maxindex = i;
		}
	printf("%d\n", maxindex);
	return 0;
}
 
