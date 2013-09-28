#include <iostream>
using namespace std;

#define maxn 1022
const int xx[4]={1, 0, -1, 0};
const int yy[4]={0, 1, 0, -1};
const char rr[4]={'R', 'T', 'L', 'B'};
int n, m, quex[maxn*maxn], quey[maxn*maxn], s, t, hx, hy, sum;
bool tutu[maxn][maxn]={0}, used[maxn][maxn]={0};

int pre(int x)
{
	++x;
	if(x==maxn*maxn)
		x=0;
	return x;
}

void work1()
{

//	cout<<"work1"<<endl;

	int x, y;
	hx=maxn;
	hy=maxn;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d", &x, &y);
		tutu[x][y]=true;
		
		if(x<hx || (x==hx && y<hy))
		{
			hx=x;
			hy=y;
		}
	}

	s=0, t=1;
	quex[1]=hx;
	quey[1]=hy;
	used[hx][hy]=true;

	printf("%d %d\n", hx, hy);

	while(pre(t)!=s)
	{
		s=pre(s);

		hx=quex[s];
		hy=quey[s];
//		cout<<hx<<' '<<hy<<' ';

		for(int i=0;i<4;++i)
			if(tutu[hx+xx[i]][hy+yy[i]] && !used[hx+xx[i]][hy+yy[i]])
			{
				printf("%c", rr[i]);
				t=pre(t);
				quex[t]=hx+xx[i];
				quey[t]=hy+yy[i];
				used[hx+xx[i]][hy+yy[i]]=true;
			}
		
		if(s!=t)
			printf(",\n");
		else
		{
			printf(".\n");
			return ;
		}
	}

}

void work2()
{
//	cout<<"work2"<<endl;

	scanf("%d", &m);
	tutu[n][m]=true;
	sum=1;
	s=0, t=1;
	quex[1]=n;
	quey[1]=m;
	char ch;
	cin>>ch;
	while(ch!='.')
	{
		s=pre(s);
		hx=quex[s];
		hy=quey[s];
		while(ch!=',')
		{
			t=pre(t);
			++sum;
			if(ch=='R')
			{
				tutu[hx+1][hy]=true;
				quex[t]=hx+1;
				quey[t]=hy;
			}
			else
				if(ch=='T')
				{
					tutu[hx][hy+1]=true;
					quex[t]=hx;
					quey[t]=hy+1;
				}
				else
					if(ch=='L')
					{
						tutu[hx-1][hy]=true;
						quex[t]=hx-1;
						quey[t]=hy;
					}
					else
						if(ch=='B')
						{
							tutu[hx][hy-1]=true;
							quex[t]=hx;
							quey[t]=hy-1;
						}
			cin>>ch;
		}

		cin>>ch;
	}

	printf("%d\n", sum);
	for(int i=1;i<=10;++i)
	{
		for(int j=1;j<=10;++j)
			if(tutu[i][j])
				printf("%d %d\n", i, j);
	}
}

int main()
{
	scanf("%d", &n);
	if(getchar()=='\n')
		work1();
	else
		work2();


	return 0;
}