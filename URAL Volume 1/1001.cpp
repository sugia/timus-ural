#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;
string str[399999];
unsigned __int64 tmp;
int main(){
	int n=0;
	while(cin>>str[++n]);
	--n;
	for(int i=n;i>=1;--i){
		tmp=0;
		for(int j=0;j<str[i].length();++j)
			if(str[i][j]-'0'>=0 && str[i][j]-'0'<=9)
				tmp=tmp*10+str[i][j]-'0';
		printf("%.4lf\n", sqrt((double)tmp));
	}
	return 0;
}