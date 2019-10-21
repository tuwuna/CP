#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int N = 5e5 + 5;

int n, m, a[N], sum[20][N];
vector <int> pos[N];

int cnt(int l, int r, int x) {
	return upper_bound(pos[x].begin(), pos[x].end(), r) - lower_bound(pos[x].begin(), pos[x].end(), l);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]].push_back(i);
		for (int j = 0; j < 20; j++) {
			sum[j][i] = (a[i] >> j) & 1;
		}
	}
	for (int j = 0; j < 20; j++) {
		for (int i = 1; i <= n; i++) {
			sum[j][i] += sum[j][i - 1];
		}
	}
	while (m--) {
		int l, r;
		cin >> l >> r;
		int ans = 0;
		for (int j = 0; j < 20; j++) {
			if (sum[j][r] - sum[j][l - 1] > (r - l + 1) / 2) {
				ans += 1 << j;
			}
		}
		if (cnt(l, r, ans) > (r - l + 1) / 2) {
			cout << ans << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
}
