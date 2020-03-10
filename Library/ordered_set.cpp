#include "bits/stdc++.h"
using ll = long long;
using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7;

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
	
};

ordered_set os;

int main() {
	os.update(4, 2); // 4 4
	os.update(6, 1); // 4 4 6
	os.update(4, -1); // 4 6
	cout << os.find_by_order(2); // 6
	cout << os.find_by_key(6); // 1
}
