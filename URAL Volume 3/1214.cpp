
#include <stdio.h>
int main(){
	long x, y;
	scanf("%ld %ld", &x, &y);
	if(x<=0 || y<=0) printf("%ld %ld\n", x, y);
	else{
		if(x%2 != y%2) printf("%ld %ld\n", y, x);
		else printf("%ld %ld\n", x, y);
	}
	return 0;
}
