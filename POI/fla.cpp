#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int N = 1001;

int n, x, a, b, X, px = 0, yu = 0, yd = 0;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> X;
	for (int i = 1; i <= n; i++) {
		cin >> x >> a >> b;
		yu += x - px;
		yd -= x - px;
		yu = min(yu, b - 1);
		yd = max(yd, a + 1);
		if ((x + yu) % 2 != 0) {
			yu--;
		}
		if ((x + yd) % 2 != 0) {
			yd++;
		}
		if (yd > yu) {
			return cout << "NIE", 0;
		}
		px = x;
	}
	cout << (x + yd) / 2;
}
