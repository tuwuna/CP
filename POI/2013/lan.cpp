#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int N = 1e6 + 1;

int n, m, ans = 0, l[N], c[N], a[N], orc[N], cnt[N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	int sum = 0;
	for (int i = 1; i <= m; i++) {
		cin >> l[i];
		sum += l[i];
		if (sum > n) {
			return cout << 0, 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> c[i];
		orc[c[i]] = l[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= sum; i++) {
		cnt[a[i]]++;
	}
	int bad = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] != orc[i]) {
			bad++;
		}
	}
	if (!bad) ans++;
	for (int i = sum + 1; i <= n; i++) {
		int p = i - sum;
		cnt[a[p]]--;
		if (cnt[a[p]] + 1 == orc[a[p]]) bad++;
		if (cnt[a[p]] == orc[a[p]]) bad--;
		cnt[a[i]]++;
		if (cnt[a[i]] - 1 == orc[a[i]]) bad++;
		if (cnt[a[i]] == orc[a[i]]) bad--;
		if (!bad) ans++;
	}
	cout << ans;
}
