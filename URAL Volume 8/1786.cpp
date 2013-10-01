#include <iostream>
#include <string>
using namespace std;
string str, Sandro="Sandro";
int ans=22;
int main(){
	cin>>str;
	for(int i=0;i<str.length()-5;++i){
		int tmp=0;
		for(int j=0;j<6;++j)
			if(str[i+j]!=Sandro[j]){
				if(tolower(str[i+j])==tolower(Sandro[j])) ++tmp;
				else if((isupper(str[i+j]) && islower(Sandro[j])) || (islower(str[i+j]) && isupper(Sandro[j]))) tmp+=2;
					 else ++tmp;
			}
		if(tmp<ans) ans=tmp;
	}
	cout<<ans*5<<endl;
	return 0;
}