#include <iostream>
#include <string>
using namespace std;
#define maxn 122
double finishTime[maxn], runningTime[maxn], bestTime;
int n, minute, top, besti;
string str[maxn], ans[maxn], tmp;
char ch;
int main(){
	scanf("%d", &n);
	bestTime=2147483647;
	for(int i=0;i<n;++i){
		cin>>str[i];
		scanf("%d:%lf", &minute, &runningTime[i]);
		runningTime[i]+=minute*60, finishTime[i]=runningTime[i]+i*30;
	}
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			if(finishTime[i]>finishTime[j]){swap(finishTime[i], finishTime[j]), swap(runningTime[i], runningTime[j]), swap(str[i], str[j]);}
	bestTime=runningTime[0], top=0, ans[++top]=str[0];
	for(int i=1;i<n;++i)
		if(runningTime[i]<bestTime){ans[++top]=str[i], bestTime=runningTime[i];}
	for(int i=1;i<top;++i)
		for(int j=i+1;j<=top;++j)
			if(ans[i]>ans[j]) swap(ans[i], ans[j]);
	printf("%d\n", top);
	for(int i=1;i<=top;++i) cout<<ans[i]<<endl;
	return 0;
}