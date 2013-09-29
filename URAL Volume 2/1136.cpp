//#include "stdafx.h"
#include <iostream>
using namespace std;

#define maxn 3022
int a[maxn];

struct node
{
	int data;
	node *l, *r;
};

void ct(int x, node *y)
{
	if(x<y->data)
	{
		if(y->l==NULL)
		{
			node *q;
			q=new node;
			q->data=x;
			q->l=NULL;
			q->r=NULL;

			y->l=q;
		}
		else
			ct(x, y->l);
	}

	if(x>y->data)
	{
		if(y->r==NULL)
		{
			node *q;
			q=new node;
			q->data=x;
			q->l=NULL;
			q->r=NULL;

			y->r=q;
		}
		else
			ct(x, y->r);
	}
}

void pt(node *x)
{
	if(x->r!=NULL)
		pt(x->r);
	if(x->l!=NULL)
		pt(x->l);
	printf("%d ", x->data);
}


int main()
{
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;++i)
		scanf("%d", &a[i]);

	node *root;
	root=new node;
	root->data=a[n];
	root->l=NULL;
	root->r=NULL;

	for(int i=n-1;i>=1;--i)
		ct(a[i], root);

	pt(root);
	return 0;
}