#include<stdio.h>
#include<stdlib.h>
int main(){
    int i=1000000;
    for(;i>0;i--)
        printf("%c",(rand()%26)+97);
    return 0;
}
