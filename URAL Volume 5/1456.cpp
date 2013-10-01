#include <iostream>
#include <vector>
using namespace std;
const int maxint=2147483647;
int a, n, phi, ans;
vector<int> prime, times;
int gcd(int x, int y){
	while(y!=0){
		int r=x%y;
		x=y, y=r;
	}
	return x;
}
int getphi(int x){
	int xx=x, ret=1;
	for(int i=2;i*i<=xx;++i)
		if(x%i==0){
			int tmp=1;
			while(x%i==0){tmp*=i, x/=i;}
			ret*=(tmp-tmp/i);
		}
	if(x!=1)ret*=(x-1);
	return ret;
}
void resolve(int x){
	prime.clear(), times.clear();
	int xx=x;
	for(int i=2;i*i<=xx;++i)
		if(x%i==0){
			int tmp=0;
			while(x%i==0){x/=i, ++tmp;}
			prime.push_back(i), times.push_back(tmp);
		}
	if(x!=1){prime.push_back(x), times.push_back(1);}
}
int km(int x, int y, int z){
	if(y==0)return 1;
	if(y==1)return x%z;
	long long tmp=km(x, y/2, z)%z;
	if(y%2==0)return tmp*tmp%z;
	else return tmp*tmp%z * (x%z) %z;
}
void dfs(int step, int cur){
	if(step==prime.size()){
		if(km(a, cur, n)==1)ans=min(ans, cur);
		return ;
	}
	int p=1;
	for(int i=0;i<=times[step];++i){dfs(step+1, cur*p), p*=prime[step];}
}
int main(){
	cin>>a>>n;
	if(gcd(a, n)!=1){
		cout<<0<<endl;
		return 0;
	}
	phi=getphi(n), resolve(phi), ans=maxint, dfs(0, 1);
	cout<<ans<<endl;
	return 0;
}