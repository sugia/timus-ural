#include <cstdio>
double a, b, c;
int main(){
	scanf("%lf%lf%lf", &a, &b, &c);
	printf("%.0lf\n", 1000/(1/a+1/b+1/c));
	return 0;
}