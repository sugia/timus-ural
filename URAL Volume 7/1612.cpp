#include <iostream>
#include <cstring>
using namespace std;
char str[10010], a1[] = "tram ", b1[] = "trolleybus ";
int main(){
    int a = 0, b = 0;
    while (fgets(str, 10005, stdin)){
        int n = strlen(str);
        for (int i = 0; i < n; ++i)
			if(!isalpha(str[i]))str[i] = ' ';
        for (char* st1 = strstr(str, a1); st1 != NULL; ++a, st1 = strstr(st1, a1))++st1;
        for (char* st2 = strstr(str, b1); st2 != NULL; ++b, st2 = strstr(st2, b1))++st2; 
    }
    if(a>b)printf("Tram driver\n");
    if(b>a)printf("Trolleybus driver\n");
    if(a==b)printf("Bus driver\n");
    return 0;
}