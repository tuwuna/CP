struct euler_orz {

	int id, tin[M], tout[M];

	void dfs(int v, int p) {
		tin[v] = ++id;
		for (auto u : adj[v]) {
			if (u != p) {
				dfs(u, v);
			}
		}
		tout[v] = ++id;
	}

	void setup() {
		dfs(1, 0);
	}

	void update(int v, int x) {
		seg.update(1, 1, id, tin[v], tin[v], x);
		seg.update(1, 1, id, tout[v], tout[v], x);
	}

	void update_subtree(int v, int x) {
		seg.update(1, 1, id, tin[v], tout[v], x);
	}

	ll query(int v) {
		return seg.query(1, 1, id, tin[v], tout[v]) >> 1;
	}

} tree;
