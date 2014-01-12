#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
 
#define ep 1e-8
struct node{
    double x, y;
};
 
struct square{
    node a, b, c, d;
    double dis;
    int k;
}p[55];
 
node st;
int n;
 
int cmp(square s, square t){
    if(fabs(s.dis-t.dis) < ep) return s.k < t.k;
	return s.dis < t.dis;
}

double dis(node s, node t){
    return sqrt((s.x-t.x)*(s.x-t.x) + (s.y-t.y)*(s.y-t.y));
}

double get(node p1, node p2, node p3){
    double a, b, c;
    a = dis(p2, p3);
    if(a < ep) return 0;
    b = dis(p1, p3);
    if(b < ep) return 0;
    c = dis(p1, p2);
    if(c < ep) return a;
    if(a*a >= b*b+c*c) return b;
    if(b*b >= a*a+c*c) return a;
    double l = (a+b+c)/2.0;
    double s = sqrt(l*(l-a)*(l-b)*(l-c));
    return 2*s/c;
}

double multi(node p1, node p2, node p0){
	return fabs((p1.x-p0.x)*(p2.y-p0.y) - (p1.y-p0.y)*(p2.x-p0.x));
}

int insquare(node st, int t){
	double ans1, ans2;
	ans1 = (multi(st, p[t].a, p[t].b) + multi(st, p[t].b, p[t].c) + multi(st, p[t].c, p[t].d) + multi(st, p[t].d, p[t].a))/2.0;
	ans2 = (p[t].a.x-p[t].b.x)*(p[t].a.x-p[t].b.x) + (p[t].a.y-p[t].b.y)*(p[t].a.y-p[t].b.y);
	if(fabs(ans1-ans2) < ep) return 1;
	return 0;
}

void getdis(int t){
    p[t].k = t;
    if(insquare(st, t)) p[t].dis = 0; return;
   
    double l = 10000000000, len;
    len = get(p[t].a, p[t].b, st);
    if(len < l) l = len;
    len = get(p[t].b, p[t].c, st);
    if(len < l) l = len;
    len = get(p[t].c, p[t].d, st);
    if(len < l) l = len;
    len = get(p[t].d, p[t].a, st);
    if(len < l) l = len;
    p[t].dis = l;
}
 
int main(){
    int i;
    scanf("%d", &n);
    double x1, x2, y1, y2;
    for(i = 1; i <= n; i ++){
        scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
        p[i].a.x = x1; p[i].a.y = y1;
        p[i].b.x = (x1+x2+y2-y1)/2.0; p[i].b.y = (y1+y2+x1-x2)/2.0;;
        p[i].c.x = x2; p[i].c.y = y2;
        p[i].d.x = (x1+x2-y2+y1)/2.0; p[i].d.y = (y1+y2-x1+x2)/2.0;
    }
    scanf("%lf%lf", &st.x, &st.y);
    for(i = 1; i <= n; i ++) getdis(i);
    stable_sort(p+1, p+n+1, cmp);
    for(i = 1; i < n; i ++) printf("%d ", p[i].k);
    
    printf("%d\n", p[i].k);
    return 0;
}
