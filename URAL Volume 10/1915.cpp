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

const int maxn=2e6+22;
int n, tmp;
vector<int> vec;
int data[maxn];
int s=0, t=maxn-1;
int tot=0;

int pre(int x)
{
    if(x==0)
        return maxn-1;
    else
        return x-1;    
}

int nex(int x)
{
    if(x==maxn-1)
        return 0;
    else
        return x+1;    
}


void display()
{
    if(tot==0)
        return ;
    int id=s;
    while(id!=t)
    {
        printf("%d ", data[id]);
        id=nex(id);            
    }
    printf("%d\n", data[id]);
         
}
int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d", &tmp);
        if(tmp<0)
        {
            printf("%d\n", data[t]);
            t=pre(t);   
            --tot;     
        }        
        else
            if(tmp==0)
            {
                vec.clear();
                int id=t;
                for(int j=1;j<=tot;++j)
                {
                    vec.push_back(data[id]);
                    id=pre(id);
                    if(vec.size()+tot>=n)
                        break;        
                }
                for(int j=0;j<vec.size();++j)
                {
                    s=pre(s);
                    data[s]=vec[j];  
                    ++tot;      
                }
            }
            else
            {
                ++tot;
                t=nex(t);
                data[t]=tmp;        
            }
                
        //display();
    }    
    
    //system("pause");
    return 0;
}