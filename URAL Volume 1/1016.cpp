#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
 
using namespace std;
 
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int jc[6] = {1, 1, 2, 6, 24, 120};
 
struct Cq{
	int x, y, s[7], ss, v;
}q[100000];
 
struct Cq2{
	int x, y, k;
}g[10][10][721];
 
bool inq[10][10][721];
int d[10][10][721];
 
int sx, sy, tx, ty, vv[7];
 
void roll(int o[], int d){
	if(d == 0) d = o[5], o[5] = o[4], o[4] = o[3], o[3] = o[6], o[6] = d;
	else if(d == 1) d = o[5], o[5] = o[2], o[2] = o[3], o[3] = o[1], o[1] = d;
	else if(d == 2) d = o[5], o[5] = o[6], o[6] = o[3], o[3] = o[4], o[4] = d;
	else if(d == 3) d = o[5], o[5] = o[1], o[1] = o[3], o[3] = o[2], o[2] = d;
}
 
int calc(int o[]){
	bool u[7];
	int i, j, k, l, s;
	s = 0, j = 0;
	memset(u, 1, sizeof(u));
	for(i = 5 ; i >= 0 ; i--){
		l = 0;
		j++;
		u[o[i]] = false;
		for(k = 1 ; k <= o[i] ; k++) if(u[k]) l++;
		s += jc[i] * l;
	}
	return s;
}
 
void print(int x, int y, int k){
	if(x == sx && y == sy){
		cout << ' ' << char(x + 'a') << char(y + '1');
		return;
	}
	print(g[x][y][k].x, g[x][y][k].y, g[x][y][k].k);
	cout << ' ' << char(x + 'a') << char(y + '1');
}
 
void work(){
	string t1, t2;
	int i, j, k, l;
	int sm[7];
	cin >> t1 >> t2;
	sx = t1[0] - 'a', sy = t1[1] - '1';
	tx = t2[0] - 'a', ty = t2[1] - '1';
	k = 0;
	for(i = 1 ; i <= 6 ; i++) cin >> vv[i], q[0].s[i] = i;
	int op = 0, cl = 1;
	q[0].x = sx, q[0].y = sy, q[0].v = 0, q[0].ss = calc(q[0].s);
	memset(d, 0x0f, sizeof(d));
	memset(g, 0xff, sizeof(g));
 
	d[sx][sy][q[0].ss] = vv[q[0].s[5]];
	inq[sx][sy][q[0].ss] = true;
	while(op < cl){
		int tt[7], tk[7];
		memcpy(tt, q[op].s, sizeof(tt));
		for(k = 0 ; k <= 3 ; k++){
			if(q[op].x + dx[k] < 0 || q[op].x + dx[k] > 7) continue;
			if(q[op].y + dy[k] < 0 || q[op].y + dy[k] > 7) continue;
 
			memcpy(tk, tt, sizeof(tt));
			roll(tk, k);
			j = calc(tk);
			if(d[q[op].x + dx[k]][q[op].y + dy[k]][j] > d[q[op].x][q[op].y][q[op].ss] + vv[tk[5]]){
				d[q[op].x + dx[k]][q[op].y + dy[k]][j] = d[q[op].x][q[op].y][q[op].ss] + vv[tk[5]];
				g[q[op].x + dx[k]][q[op].y + dy[k]][j].x = q[op].x;
				g[q[op].x + dx[k]][q[op].y + dy[k]][j].y = q[op].y;
				g[q[op].x + dx[k]][q[op].y + dy[k]][j].k = q[op].ss;
				if(!inq[q[op].x + dx[k]][q[op].y + dy[k]][j])
				{
					inq[q[op].x + dx[k]][q[op].y + dy[k]][j] = true;
					q[cl].x = q[op].x + dx[k];
					q[cl].y = q[op].y + dy[k];
					q[cl].ss = j;
					memcpy(q[cl].s, tk, sizeof(tk));
					cl++;
				}
			}
		}
		inq[q[op].x][q[op].y][q[op].ss] = false;
		op++;
	}
	l = 99999999, k = 0;
	for(j = 0 ; j <= 720 ; j++)
	if(d[tx][ty][j] < l) l = d[tx][ty][j], k = j;
	cout << l;
	print(tx, ty, k);
	cout << endl;
}
 
int main(){
	work();
	return 0;
}