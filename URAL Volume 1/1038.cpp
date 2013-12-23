//#include "stdafx.h"
#include <iostream>
using namespace std;

int main(){
	int ans=0;
	int now=0;
	char ch;
	while(scanf("%c", &ch)!=EOF){
		if(now==0){
			if('a'<=ch && ch<='z') ++ans;
			if(('a'<=ch && ch<='z') || ('A'<=ch && ch<='Z')) now=1;
		}
		else
		if(now==1){
			if('A'<=ch && ch<='Z') ++ans;
			if(!(('a'<=ch && ch<='z') || ('A'<=ch && ch<='Z'))){
				if(ch=='?' || ch=='.' || ch=='!') now=0;
				else now=2;
			}
		}
		else if(now==2){
			if(('a'<=ch && ch<='z') || ('A'<=ch && ch<='Z')) now=1;
			if(ch=='?' || ch=='.' || ch=='!') now=0;
		}
	}

	printf("%d\n", ans);
	return 0;
}
