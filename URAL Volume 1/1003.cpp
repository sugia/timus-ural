#include <iostream>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;

const int block=10000;
const int mod=6000;
const int maxn=20000;

int hashTable[maxn];
int father[maxn];

int callHash(int num){
	int pos=num%mod;
	while(hashTable[pos]!=-1 && hashTable[pos]!=num)
		pos=(pos+1)%mod;
	hashTable[pos]=num;
	return pos;
}

int find(int x){
	int root=x;
	while(root!=father[root])
		root=father[root];
	while(x!=root){
		int tmp=father[x];
		father[x]=root;
		x=tmp;
	}
	return root;
}

void combine(int x, int y){
	int p=find(x);
	int q=find(y);
	if(p!=q)
		father[p]=q;
}

int main(){
	while(1){
		int len;
		cin>>len;
		if(len==-1) break;

		int n;
		cin>>n;
		memset(hashTable, 0xff, sizeof(hashTable));
		for(int i=0;i<maxn;++i)
			father[i]=i;

		int count;
		for(count=1;count<=n;++count){
			int a, b;
			string signal;
			cin>>a>>b>>signal;
			bool even=(signal=="even");
			a=callHash(a-1);
			b=callHash(b);

			if(even){
				if(find(a)==find(b+block)) break;
				combine(a, b);
				combine(a+block, b+block);
			}
			else{
				if(find(a)==find(b)) break;
				combine(a, b+block);
				combine(a+block, b);
			}
		}
		int ans=count-1;
		int tmpa, tmpb;
		string tmpstr;
		for(++count;count<=n;++count)
			cin>>tmpa>>tmpb>>tmpstr;
		cout<<ans<<endl;
	}
	return 0;
}