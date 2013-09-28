#include <iostream>
using namespace std;
int pat(int r[],int i,int j){
	int p=r[i];
	while (i<j){
		while (i<j&&r[j]>=p) j--;
		if(i<j) r[i++]=r[j];
		while (i<j&&r[i]<=p) i++;
		if(i<j) r[j--]=r[i];
	}
	r[i]=p;
	return i;
}
void qsort(int r[],int low,int high){
	if(low<high){
		int p=pat(r,low,high);
		qsort(r,low,p-1);
		qsort(r,p+1,high);
	}
}
int n,num[10001];
bool flag[10001]={0};
struct node{
	int l,r;
	bool f;
}nodes[5001];
int main(){
	cin>>n;
	int i,j,a,b,m=0,x,y;
	char c;
	for (i=0;i<n;i++){
		cin>>a>>b>>c;
		nodes[i].l=a;
		for (j=0;j<m;j++) if(num[j]==a) break;
		if(j==m) num[m++]=a;
		nodes[i].r=b;
		for (j=0;j<m;j++) if(num[j]==b) break;
		if(j==m) num[m++]=b;
		nodes[i].f=(c=='b')?1:0;
	}
	for (j=0;j<m;j++) if(num[j]==1000000000) break;
	if(j==m) num[m++]=1000000000;
	for (j=0;j<m;j++) if(num[j]==0) break;
	if(j==m) num[m++]=0;
	qsort(num,0,m-1);

	for (i=0;i<n;i++){
		for (j=0;j<m-1&&nodes[i].r>=num[j+1];j++)
			if(nodes[i].l<=num[j]&&nodes[i].r>=num[j+1]) flag[j]=nodes[i].f;

	}
	i=0;
	x=0;y=-1;
	while (i<m-1){
		if(flag[i]) {i++;continue;}
		j=i+1;
		while (j<m-1&&!flag[j]) j++;
		if(num[j]-num[i]>y-x) {y=num[j];x=num[i];}
		i=j;
	}
	cout<<x<<' '<<y;
	return 0;
}