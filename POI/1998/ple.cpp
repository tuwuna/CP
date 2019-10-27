#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int N = 1001;

int T, A, n, t[N], a[N], w[N], dp[N][25][85];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> T >> A >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> a[i] >> w[i];
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 21; j >= 0; j--) {
			for (int k = 79; k >= 0; k--) {
				if (j >= t[i] && k >= a[i]) {
					dp[i][j][k] = min(dp[i - 1][j][k], dp[i - 1][j - t[i]][k - a[i]] + w[i]);
				} else {
					dp[i][j][k] = min({dp[i - 1][j][k], dp[i][j + 1][k], dp[i][j][k + 1], dp[i][j + 1][k + 1]});
				}
			}
		}
	}
	cout << dp[n][T][A];
}
