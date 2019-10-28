#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1e9;

struct __int77 {
	pair <ll, ll> a;
	__int77 operator + (__int77 b) {
		__int77 ans;
		ans.a = {a.first + b.a.first + (a.second + b.a.second) / mod, (a.second + b.a.second) % mod};
		return ans;
	}
};

ostream& operator << (ostream &os, __int77 const& ans) {
	if (ans.a.first == 0) return os << ans.a.second;
	return os << ans.a.first << setw(9) << setfill('0') << ans.a.second;
}

__int77 ans, dp[101][404], sum[101][404];

int main() {
	int n, k;
	cin >> n >> k;
	for (int j = 0; j <= k; j++) {
		for (int i = 1; i <= n; i++) {
			dp[i][j] = (i >= 2 ? sum[i - 2][max(j - i, 0)] : __int77{{0, 0}}) + __int77{{0, i > j}};
			sum[i][j] = sum[i - 1][j] + dp[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		ans = ans + dp[i][k];
	}
	cout << ans;
}
