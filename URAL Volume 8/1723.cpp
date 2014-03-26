#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
#define maxn 26
int a[maxn]={0};
string str;
int main(){
	cin>>str;
	for(int i=0;i<str.size();++i)
		++a[int(str[i]-'a')];
	int most=0, step;
	for(int i=0;i<26;++i)
		if(a[i]>most){
			most=a[i];
			step=i;
		}
	cout<<char(step+int('a'))<<endl;
	return 0;
}
