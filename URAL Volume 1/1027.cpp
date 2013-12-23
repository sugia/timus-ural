//#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string>
 
using namespace std;
 
string st, tmp;
int len;
 
void init(){
	while(getline(cin, tmp)) st += tmp;
}
 
string check(){
	int i, le = 0;
	bool inn = false;
	len = st.length();
	for(int i = 0 ; i < len ; i++){
		if(st[i] != '*' && inn) continue;
		if(st[i] == '('){
			if(i < len - 1 && st[i + 1] == '*') i++, inn = true;
			else le++;
			continue;
		}
		if(st[i] == '*'){
			if(i < len - 1 && st[i + 1] == ')' && inn) i++, inn = false;
			continue;
		}
		if(st[i] >= '0' && st[i] <= '9')  continue;
		if(st[i] == '=' || st[i] == '+' || st[i] == '-' || st[i] == '/') continue;
		if(st[i] == ')'){
			le--;
			if(le < 0) return "NO\n";
			continue;
		}
		if(le == 0) continue;
		return "NO\n";
	}
	if(inn || le > 0) return "NO\n";
	return "YES\n";
}
 
void work(){
	cout << check();
}
 
int main(){
	init();
	work();
	return 0;
}
