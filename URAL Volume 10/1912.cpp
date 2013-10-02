#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#define ll long long 
#define oo 1000000007
#define MAXN 300
using namespace std; 
struct node
{
       int y1,x1,y2,x2,dis;
}h,p;
int n,m,way[8][2]={{-1,-0},{1,0},{0,1},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1}};
char arc[MAXN<<1][MAXN<<1];
queue<node> myqueue; 
bool H[300][300][8];
bool hash(node h)
{
       int i,j;
       for (i=0;i<8;i++) 
          if (h.y1+way[i][0]==h.y2 && h.x1+way[i][1]==h.x2)  break; 
       if (H[h.y1][h.x1][i]) return false;
       H[h.y1][h.x1][i]=true;
       return true;
}
bool legal(node h)
{
       int i,j;
       for (i=0;i<8;i++) 
          if (h.y1+way[i][0]==h.y2 && h.x1+way[i][1]==h.x2) return true; 
       if (h.x1==h.x2 && h.y1==h.y2) return false;
       return false;
}
bool isans(node h)
{
       int p=0;
       if (h.x1<1 || h.y1<1 || h.x1>m || h.y1>n) p++;
       if (h.x2<1 || h.y2<1 || h.x2>m || h.y2>n) p++;
       if (p==2) return true;
       return false;
}
bool canuse(node h)
{
       if (h.x1<0 || h.y1<0 || h.x2<0 || h.y2<0) return false;
       if (h.x1>m+2 || h.y1>n+2 || h.x2>m+2 || h.y2>n+2) return false;
       return true;
}
int BFS()
{
       int i,j;
       node p;
       while (!myqueue.empty()) myqueue.pop(); 
       memset(H,0,sizeof(H));
       h.dis=0;
       hash(h); 
       myqueue.push(h);
       while (!myqueue.empty())
       {
               h=myqueue.front();
               myqueue.pop();
               if (isans(h)) break;  
               for (i=0;i<4;i++)
               {
                      p=h; 
                      p.y1+=way[i][0],p.x1+=way[i][1];
                      if (canuse(p) && arc[h.y1*2+way[i][0]][h.x1*2+way[i][1]]=='.') 
                      { 
                            if (legal(p) && hash(p))
                            {
                                   if ((p.x1<1 || p.y1<1 || p.x1>m || p.y1>n) && (h.x1<1 || h.y1<1 || h.x1>m || h.y1>n))
                                       p.dis=h.dis;
                                   else
                                       p.dis=h.dis+1;
                                   myqueue.push(p); 
                            }
                      }
                      p=h; 
                      p.y2+=way[i][0],p.x2+=way[i][1];
                      if (canuse(p) && arc[h.y2*2+way[i][0]][h.x2*2+way[i][1]]=='.') 
                      { 
                             if (legal(p) && hash(p))
                             {
                                   if ((p.x2<1 || p.y2<1 || p.x2>m || p.y2>n) && (h.x2<1 || h.y2<1 || h.x2>m || h.y2>n))
                                       p.dis=h.dis;
                                   else
                                       p.dis=h.dis+1;
                                   myqueue.push(p); 
                             }
                      }
               } 
       }
       if (isans(h)) return h.dis;
       return -1;       
}
int main()
{
       int i,j; 
       while (~scanf("%d%d",&n,&m))
       { 
               gets(arc[0]);   
               for (i=1;i<=2*n+1;i++) gets(arc[i]+1); 
               for (i=0;i<=2*n+3;i++) arc[i][0]=arc[i][2*m+2]='.';
               for (i=0;i<=2*m+3;i++) arc[0][i]=arc[2*n+2][i]='.';
               for (i=1;i<=2*n+1;i++)
                  for (j=1;j<=2*m+1;j++)
                  {
                         if (arc[i][j]=='1') h.y1=i>>1,h.x1=j>>1,arc[i][j]=' ';
                         if (arc[i][j]=='2') h.y2=i>>1,h.x2=j>>1,arc[i][j]=' ';
                  }
               i=BFS();
               if (i==-1) printf("Death\n");
                       else  printf("%d\n",i);
       }
       return 0;
}
