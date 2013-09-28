//#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
 
using namespace std;
 
const int maxn = 251;
 
int n;
int a[maxn][maxn], g[maxn];
 
void init()
{
	int x;
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> x;
		while(x != -1)
		{
			a[x][i] = 1;
			cin >> x;
		}
		a[i][0] = 1;
	}
}
 
void work()
{
	int i, j, k, c;
	for(i = 1 ; i <= n ; i++)
	{
		for(c = i ; c <= n ; c++)if(a[c][i]) break;
		for(k = 0 ; k <= n ; k++) swap(a[i][k], a[c][k]);
		for(j = i + 1 ; j <= n ; j++)
		if(a[j][i])
		{
			a[j][0] ^= a[i][0];
			for(k = i ; k <= n ; k++)
				a[j][k] ^= a[i][k];
		}
	}
	for(i = n ; i >= 1 ; i--)
	{
		int t = 0;
		for(j = i + 1 ; j <= n ; j++)
			t ^= g[j] & a[i][j];
		g[i] = a[i][0] ^ t;
	}
	for(i = 1 ; i <= n ; i++)
	if(g[i])
		cout << i << ' ';
}
 
int main()
{
	init();
	work();
	return 0;
}