#include <cstdio>
#include <cstring>
const int maxn=50002;
const int maxm=302;

int n;
int len[maxn];
int ans[maxn];
int bl, sl;
int f[maxm];
int pre[maxm];
char d[maxn][52];
char phone[maxm];
char b[maxm];

bool check(int p, int j){
	for(int i=1;i<=len[j];++i)
		if(phone[p+i]!=b[d[j][i-1]])
			return false;
	return true;
}

int main(){
	freopen("s.in", "r", stdin);
	freopen("s.out", "w", stdout);
	b['i']=b['j']='1';
	b['a']=b['b']=b['c']='2';
	b['d']=b['e']=b['f']='3';
	b['g']=b['h']='4';
	b['k']=b['l']='5';
	b['m']=b['n']='6';
	b['p']=b['r']=b['s']='7';
	b['t']=b['u']=b['v']='8';
	b['w']=b['x']=b['y']='9';
	b['o']=b['q']=b['z']='0';
 
	gets(phone);
	while(phone[0]!='-'){
		bl=strlen(phone);
		for(int i=bl;i;--i)
			phone[i]=phone[i-1];
		scanf("%d\n", &n);
		for(int i=1;i<=n;++i){
			gets(d[i]);
			len[i]=strlen(d[i]);
		}
		for(int i=1;i<=bl;++i)
			f[i]=1000000000;
		memset(pre, 0, sizeof(pre));
		f[0]=0;
		for(int i=0;i<bl;++i)
			for(int j=1;j<=n;++j)
				if(i+len[j]<=bl && f[i]+1<f[i+len[j]] && check(i, j)){
					f[i+len[j]]=f[i]+1;
					pre[i+len[j]]=j;
				}
		if(f[bl]==1000000000)
			printf("No solution.\n");
		else{
			sl=0;
			for(int u=bl;u;u-=len[pre[u]])
				ans[++sl]=pre[u];
			for(int i=sl;i;--i)
				printf("%s%c", d[ans[i]], (i!=1)?' ':'\n');
		}
		gets(phone);
	}
	return 0;
}