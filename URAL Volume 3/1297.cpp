//#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 5000
#define MAXM 128

int head[MAXN * 2 + 1], succ[MAXN * 2 + 1], succran[MAXN * 2 + 1];
int sa[MAXN * 2 + 1], ran[MAXN * 2 + 1];
int letter[MAXM];

void da(char* str, int len) {
	memset(letter, 0, sizeof(letter));
	for (int i = 0; i < len; ++i)
		if (!letter[str[i]])
			letter[str[i]] = 1;
	int total = -1;
	for (int i = 0; i < MAXM; ++i)
		if (letter[i])
			letter[i] = ++total;
	memset(head, 255, sizeof(head));
	for (int i = len - 1; i >= 0; --i) {
		ran[i] = letter[str[i]];
		succ[i] = head[ran[i]];
		head[ran[i]] = i;
	}
	int j = 0;
	for (int i = 0; i < len; ++i) {
		while (head[j] == -1) ++j;
		sa[i] = head[j];
		head[j] = succ[head[j]];
	}
	
	for (int k = 1; k < len; k <<= 1) {
		for (int i = len - 1; i >= 0; --i)
			if (sa[i] - k >= 0) {
				succran[sa[i] - k] = ran[sa[i]];
				succ[sa[i] - k] = head[ran[sa[i] - k]];
				head[ran[sa[i] - k]] = sa[i] - k;
			}
		for (int i = len - 1; i >= len - k; --i) {
			succran[i] = -1;
			succ[i] = head[ran[i]];
			head[ran[i]] = i;
		}
		j = 0; total = -1;
		int preSuccran = 0, preran = 0;
		for (int i = 0; i < len; ++i) {
			while (head[j] == -1) ++j;
			sa[i] = head[j];
			if (i == 0 || preran != ran[sa[i]] || preSuccran != succran[sa[i]]) {
				preran = ran[sa[i]];
				ran[sa[i]] = ++total;
			} else {
				preran = ran[sa[i]];
				ran[sa[i]] = total;
			}
			preSuccran = succran[sa[i]];
			head[j] = succ[head[j]];
		}
	}
}

int height[MAXN * 2 + 1];

void calcHeight(char* str, int len) {
	int i, j, k = 0;
	for (i = 0; i < len; ++i) {
		if (k != 0)
			--k;
		if (ran[i] == 0)
			continue;
		j = sa[ran[i] - 1];
		
		while (str[i + k] == str[j + k])
			++k;
		height[ran[i]] = k;
	}
}

struct Node {
	int _a, _b;
	Node *_left, *_right;
	int _min_value;
} nodes[(MAXN * 2 + 1) * 2], *ptr;

void makeTree(int a, int b) {
	Node* root = ++ptr;
	root->_a = a; root->_b = b;
	if (a == b) {
		root->_min_value = height[a];
		return;
	}
	root->_left = ptr + 1;
	makeTree(a, (a + b) / 2);
	root->_right = ptr + 1;
	makeTree((a + b) / 2 + 1, b);
	root->_min_value = min(root->_left->_min_value, root->_right->_min_value);
}

int la, lb;

int minQuery(Node* root) {
	if (la <= root->_a && root->_b <= lb)
		return root->_min_value;
	int mid = (root->_a + root->_b) / 2;
	return min(la <= mid ? minQuery(root->_left) : 0x7fffffff, mid < lb ? minQuery(root->_right) : 0x7fffffff);
}

struct Arcs {
	int _s, _e;
	bool operator < (const Arcs& rh) const {
		int lenL = _e - _s + 1, lenR = rh._e - rh._s + 1;
		return lenL != lenR ? lenL > lenR :_s < rh._s;
	}
} arcs[MAXN * 2];
int total;

char buf[MAXN * 2 + 2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int len;
	while (scanf("%s", buf) != EOF) {
		len = strlen(buf);
		reverse_copy(buf, buf + len, buf + len + 1);
		buf[len] = 'a' - 1; buf[len * 2 + 1] = 0;
		da(buf, len * 2 + 1);
		calcHeight(buf, len * 2 + 1);

		total = 0;
		memset(nodes, 0, sizeof(nodes));
		ptr = nodes;
		makeTree(1, len * 2);
		int r;
		for (int i = 0; i < len; ++i) {
			la = min(ran[i], ran[2 * len - i]) + 1;
			lb = max(ran[i], ran[2 * len - i]);
			r = minQuery(nodes + 1);
			arcs[total]._e = i + r - 1;
			arcs[total]._s = i - r + 1;
			++total;
			if (i > 0) {
				la = min(ran[i], ran[2 * len - i + 1]) + 1;
				lb = max(ran[i], ran[2 * len - i + 1]);
				r = minQuery(nodes + 1);
				if (r > 0) {
					arcs[total]._e = i + r - 1;
					arcs[total]._s = i - r;
					++total;
				}
			}
		}
		sort(arcs, arcs + total);
		buf[arcs[0]._e + 1] = 0;
		printf("%s\n", buf + arcs[0]._s);
	}
	return 0;
}