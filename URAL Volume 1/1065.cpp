//#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int MAXN = 55;
const int MAXM = 1005;
 
typedef struct Coordinate {
    int x, y;
} Point, Vector, *Pptr, *Vptr;
const double INFSIMAL = 1e-6;
const double INF = 1e10;
 
inline int compare(double a, double b) {
    if (fabs(a-b) < INFSIMAL)
        return 0;
    return a<b?-1:1;
}
inline double det(int x1, int y1, int x2, int y2) {
    return x1*y2-x2*y1;
}
inline double cross(Point &a, Point &b, Point &c) {
    return det(b.x-a.x,b.y-a.y,c.x-b.x,c.y-b.y);
}
template<typename T>
T sqr(T a) {
    return a*a;
}
inline double dist(Point &a, Point &b) {
    return sqrt(double(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
 
int n, m;
Point tower[MAXN], monu[MAXM];
void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &tower[i].x, &tower[i].y);
    }
    tower[0] = tower[n];
 
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d",&monu[i].x, &monu[i].y);
    }
}
 
double graph[MAXN][MAXN];
double dis[MAXN][MAXN];
double ans = INF;
 
bool check(int id1, int id2) {
    for (int i = 1; i <= m; ++i)
        if ( cross(tower[id1],tower[id2],monu[i]) >= 0)
            return false;
    return true;
}
 
bool sameside(Point &t, Point &a, Point &b) {
    if ( 0 > (a.x-t.x)*(b.x-t.x) )
        return false;
    if ( 0 > (a.y-t.y)*(b.y-t.y) )
        return false;
    return true;
}
void work() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            graph[i][j] = INF;
 
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < n; ++j) {
            int t = i+j;
            if (t > n)
                t -= n;
            if (0 == cross(tower[i-1],tower[i],tower[t]) && sameside(tower[i],tower[i-1],tower[t]) )
                break;
            if (check(i,t))
                graph[i][t] = dist(tower[i],tower[t]);
        }
    memcpy(dis,graph,sizeof(graph));
 
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= n; ++j)
//            printf("%.2lf ", graph[i][j]);
//        putchar('\n');
//    }
 
 
    for (int k = 1; k <= n; ++k) {
        double tmp;
        for (int i = 1; i < k; ++i)
            for (int j = 1; j < k; ++j)
                if (i != j) {
                    if (ans > (tmp = dis[i][j]+graph[k][i]+graph[j][k]))
                        ans = tmp;
                }
 
        for (int i = 1; i <= n; ++i)
            if (i != k)
                for (int j = 1; j <= n; ++j)
                    if (i != j && j != k)
                        if (dis[i][j] > (tmp = dis[i][k]+dis[k][j]))
                            dis[i][j] = tmp;
    }
}
 
void output() {
    printf("%.2lf\n", ans);
}
 
int main() {
    input();
    work();
    output();
//    system("pause");
    return 0;
}