struct ordered_set {
	
	int sz = 0, bit[N];

	int size() {
		return sz;
	}

	void update(int k, int x) {
		while (k < N) {
			bit[k] += x;
			k += k & -k;
		}
		sz += x;
	}

	int find_by_order(int k) {
		int ans = 0, sum = 0;
		for (int j = 17; j >= 0; --j) {
			ans += 1 << j;
			if (ans < N && sum + bit[ans] < k) {
				sum += bit[ans];
			} else {
				ans -= 1 << j;
			}
		}
		return ans + 1;
	}
	
	int order_of_key(int k) {
		int ans = 0;
		while (k >= 1) {
			ans += bit[k];
			k -= k & -k;
		}
		return ans;
	}
	
} os;
