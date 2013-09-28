//#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
 
using namespace std;
 
class Bigint
{
	public:
	static const int sa = 200;
	int * da;
	~Bigint();
	Bigint(const int n);
	Bigint(const Bigint &a);
	Bigint operator=(const int n);
	Bigint operator=(const Bigint &a);
	Bigint operator+(const Bigint &b);
	Bigint operator*(const Bigint &b);
	friend ostream &operator<<(ostream &s, Bigint &a);
	friend istream &operator>>(istream &s, const Bigint &a);
};
 
Bigint::~Bigint()
{
	delete [] da;
}
 
Bigint::Bigint(const int n = 0)
{
	da = new int[sa];
	memset(da, 0, sizeof(int) * sa);
	da[1] = n;
	int i;
	for(i = 1 ; da[i] ; i++)
	{
		da[i + 1] += da[i] / 10000;
		da[i] %= 10;
	}
	da[0] = i - 1;
}
 
Bigint::Bigint(const Bigint &a)
{
	da = new int[sa];
	memcpy(da, a.da, sizeof(int) * sa);
}
 
Bigint Bigint::operator=(const Bigint &a)
{
	memcpy(da, a.da, sizeof(int) * sa);
	return *this;
}
 
Bigint Bigint::operator=(const int n)
{
	Bigint c(n);
	*this = c;
	return *this;
}
 
Bigint Bigint::operator+(const Bigint &b)
{
	Bigint &a = *this;
	Bigint c;
	c.da[0] = max(a.da[0], b.da[0]);
	int i;
	for(i = 1 ; i <= c.da[0] ; i++)
	{
		c.da[i] += a.da[i] + b.da[i];
		c.da[i + 1] += c.da[i] / 10000;
		c.da[i] %= 10000;
	}
	c.da[0] = i;
	while(c.da[c.da[0]] == 0 && c.da[0] > 1) c.da[0]--;
	return c;
}
 
Bigint Bigint::operator*(const Bigint &b)
{
	Bigint &a = *this;
	Bigint c;
	int i, j;
	for(i = 1 ; i <= a.da[0] ; i++)
		for(j = 1 ; j <= b.da[0] ; j++)
		{
			c.da[i + j - 1] += a.da[i] * b.da[j];
			c.da[i + j] += c.da[i + j - 1] / 10000;
			c.da[i + j - 1] %= 10000;
		}
	c.da[0] = a.da[0] + b.da[0];
	while(c.da[c.da[0]] == 0 && c.da[0] > 1) c.da[0]--;
	return c;
}
 
ostream &operator<<(ostream &s, Bigint a)
{
	int i, l;
	l = a.da[0];
	s << a.da[l];
	for(i = l - 1 ; i >= 1 ; i--)
		s << setfill('0') << setw(4) << a.da[i];
	return s;
}
 
istream &operator>>(istream &s, Bigint &a)
{
	int k, i;
	s >> k;
	Bigint c(k);
	a = c;
	return s;
}
 
int n,m;
//long long f[51][1001];
Bigint f[2][1001];
 
void work()
{
	cin >> n >> m;
	if(m % 2 == 1)
	{
		cout << 0 << endl;
		return;
	} 
	f[0][0] = 1;
	m /= 2;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 0 ; j <= m ; j++)
		{
			f[i % 2][j] = 0;
			for(int k = 0 ; k <= 9 ; k++)
			{
				if(j - k >= 0)
					f[i % 2][j] = f[i % 2][j] + f[(i - 1) % 2][j - k];
			}
		}
	cout << (f[n % 2][m] * f[n % 2][m]) << endl;
}
 
int main()
{
	work();
	return 0;
}