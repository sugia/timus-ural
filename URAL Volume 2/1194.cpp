//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int n, k;
int main()
{
	scanf("%d%d", &n, &k);
	printf("%d\n", n*(n-1)/2-k);
	return 0;
}