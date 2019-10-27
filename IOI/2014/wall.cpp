#include "wall.h"
#include <bits/stdc++.h>
#define lc (id << 1)
#define mid ((l + r) >> 1)
#define rc ((id << 1) | 1)
using namespace std;

const int N = 1 << 21, inf = 1 << 17;

int tree[N], d[N << 1], u[N << 1];

void merge(int id, int c) {
	if (d[id] <= d[c]) {
		if (u[id] <= d[c]) {
			d[c] = u[c] = u[id];
		}
		if (d[c] < u[id] && u[id] <= u[c]) {
			u[c] = u[id];
		}
	}
	if (d[c] < d[id] && d[id] <= u[c]) {
		if (u[id] <= u[c]) {
			d[c] = d[id];
			u[c] = u[id];
		} else {
			d[c] = d[id];
		}
	}
	if (u[c] < d[id]) {
		d[c] = u[c] = d[id];
	}
}

void push(int id) {
	if (id >= N) {
		tree[id - N] = max(tree[id - N], d[id]);
		tree[id - N] = min(tree[id - N], u[id]);
	} else {
		merge(id, lc);
		merge(id, rc);
	}
	d[id] = 0;
	u[id] = inf;
}

void update(int id, int l, int r, int L, int R, int vd, int vu) {
	push(id);
	if (l > R || r < L) {
		return;
	}
	if (L <= l && r <= R) {
		d[id] = vd;
		u[id] = vu;
		return;
	}
	update(lc, l, mid, L, R, vd, vu);
	update(rc, mid + 1, r, L, R, vd, vu);
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]) {
	for (int i = 0; i < N << 1; i++) {
		u[i] = inf;
	}
	for (int i = 0; i < k; i++) {
		if (op[i] == 1) {
			update(1, 1, N, left[i] + 1, right[i] + 1, height[i], inf);
		} else {
			update(1, 1, N, left[i] + 1, right[i] + 1, 0, height[i]);
		}
	}
	for (int id = 1; id < N << 1; id++) {
		push(id);
	}
	for (int i = 0; i < n; i++) {
		finalHeight[i] = tree[i];
	}
}
