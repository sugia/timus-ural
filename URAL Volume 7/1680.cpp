#include <iostream>
#include <string>
using namespace std;
#define maxn 222
string str[maxn], uni[maxn];
bool b[maxn];
int main(){
	int y, n, p, pos;
	cin>>y>>n>>p;
	getline(cin, str[0]);
	for(int i=0;i<n;++i){
		getline(cin, str[i]);
		pos=str[i].find('#');
		if(pos==-1) uni[i]=str[i];
		else uni[i]=str[i].substr(0, pos-2);
	}
	memset(b, true, sizeof(b));
	for(int i=0;i<n;++i)
		for(int j=i+1;j<=n;++j)
			if(uni[i]==uni[j]) b[j]=false;
	int ans=-1;
	for(int i=1;i<=p+1;++i){
		++ans;
		while(!b[ans]) ++ans;
	}
	cout<<str[ans]<<endl;
	return 0;
}