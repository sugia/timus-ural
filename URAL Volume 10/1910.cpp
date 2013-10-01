#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

const int maxn=1022;
int data[maxn];
int n;

int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;++i)
        scanf("%d", &data[i]);
    int id=2;
    int tot=data[1]+data[2]+data[3];
    for(int i=3;i<n;++i)
    {
        int tmp=data[i-1]+data[i]+data[i+1];
        if(tmp>tot)
        {
            tot=tmp;
            id=i;           
        }        
    }    
    printf("%d %d\n", tot, id);
    
    //system("pause");
    return 0;
}