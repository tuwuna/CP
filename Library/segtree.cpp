struct segtree_orz {
	#define lc (id << 1)
	#define rc (lc | 1)
	#define mid ((l + r) >> 1)

	ll lazy[M << 2], tree[M << 2];

	void push(int l, int r, int id) {
		tree[id] += (r - l + 1) * lazy[id];
		if (l < r) {
			lazy[lc] += lazy[id];
			lazy[rc] += lazy[id];
		}
		lazy[id] = 0;
	}
	 
	void update(int id, int l, int r, int L, int R, int V) {
		push(l, r, id);
		if (l > R || r < L) {
			return;
		}
		if (L <= l && r <= R) {
			lazy[id] = V;
			push(l, r, id);
			return;
		}
		update(lc, l, mid, L, R, V);
		update(rc, mid + 1, r, L, R, V);
		tree[id] = tree[lc] + tree[rc];
	}
	 
	ll query(int id, int l, int r, int L, int R) {
		push(l, r, id);
		if (l > R || r < L) {
			return 0;
		}
		if (L <= l && r <= R) {
			return tree[id];
		}
		return query(lc, l, mid, L, R) + query(rc, mid + 1, r, L, R);
	}
	#undef lc
	#undef rc
	#undef mid
} seg;
