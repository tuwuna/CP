#include "bits/stdc++.h"
using ll = long long;
using namespace std;
 
const int N = 2e5 + 5, MAX = 1e9, mod = 1e9 + 7;

const ll nine = 1e9;

struct __int90 {
	pair <ll, ll> a;
	bool operator < (__int90 b) {
		if (a.first < b.a.first || (a.first == b.a.first && a.second < b.a.second)) {
			return 1;
		}
		return 0;
	}
	bool operator > (__int90 b) {
		if (a.first > b.a.first || (a.first == b.a.first && a.second > b.a.second)) {
			return 1;
		}
		return 0;
	}
	bool operator == (__int90 b) {
		return a == b.a;
	}
	bool operator != (__int90 b) {
		return a != b.a;
	}
	__int90 operator + (__int90 b) {
		__int90 ans;
		ans.a = {a.first + b.a.first + (a.second + b.a.second) / nine, (a.second + b.a.second) % nine};
		return ans;
	}
	__int90 operator - (__int90 b) {
		__int90 ans;
		ans.a = {(a.first - b.a.first) * nine + (a.second - b.a.second) / nine, (a.second - b.a.second) % nine};
		return ans;
	}
	__int90 operator * (__int90 b) {
		__int90 ans;
		ans.a = {a.first * b.a.first * nine + a.second * b.a.first + a.second * b.a.second / nine, (a.second * b.a.second) % nine};
		return ans;
	}
	__int90 operator / (__int90 b) {
		// binary search not yet implemented
		return __int90{{0, 0}};
	}
	
};

ostream& operator << (ostream &os, __int90 const& ans) {
	if (ans.a.first == 0) return os << ans.a.second;
	return os << ans.a.first << setw(9) << setfill('0') << ans.a.second;
}

int main() {
	__int90 a = {{3e4, 1e9}}, b = {{3e4, 0}};
	cout << a << ' ' << b << '\n';
	// 300001000000000 30000000000000
	cout << a + b << ' ' << a - b << '\n';
	// 60001000000000 1000000000
	cout << a * b << ' ' << a / b << '\n'; 
	// 900030000000000000000000000 0
	cout << (a > b) << ' ' << (a == a) << '\n'; // 1 1
	cout << (a < b) << ' ' << (a != a) << '\n'; // 0 0
}
