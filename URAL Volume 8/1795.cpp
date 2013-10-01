#include <iostream>
#include <string>
using namespace std;
#define maxn 1022
int sa[maxn], ca[maxn], m, n;
string sn[maxn], cn[maxn];
int main(){
	cin>>m;
	for(int i=1;i<=m;++i) cin>>sa[i]>>sn[i]>>sn[i];
	cin>>n;
	for(int i=1;i<=n;++i) cin>>ca[i]>>cn[i]>>cn[i];
	int ans=0, s=1, t=n;
	while(s<=t){
		bool flag=false;
		int it;
		for(int i=1;i<=m;++i)
			if(sn[i]==cn[s]){
				flag=true, it=i;
				break;
			}
		if(!flag){++s, ++ans;}
		else if(sa[it]==0){++s, ++ans;}
			 else if(ca[s]<=sa[it]){sa[it]-=ca[s], ++s, ++ans;}
				  else if(ca[s]>sa[it]){
                           ca[s]=sa[it], ++ans;
						   if(s<t){
						       string tmpstr=cn[s];
                               cn[s]=cn[s+1], cn[s+1]=tmpstr;
							   int ctmp=ca[s];
							   ca[s]=ca[s+1], ca[s+1]=ctmp;
						   }
						else ++s;
					   }
	}
	cout<<ans<<endl;
	return 0;
}