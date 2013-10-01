//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	if(n<5)
		printf("few");
	else
		if(n<10)
			printf("several");
		else
			if(n<20)
				printf("pack");
			else
				if(n<50)
					printf("lots");
				else
					if(n<100)
						printf("horde");
					else
						if(n<250)
							printf("throng");
						else
							if(n<500)
								printf("swarm");
							else
								if(n<1000)
									printf("zounds");
								else
									printf("legion");
	printf("\n");
	return 0;
}