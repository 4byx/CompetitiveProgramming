#include <bits/stdc++.h>
using namespace std;

// gcd
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

// extended gcd ax + by = gcd(a,b)
vector<int> extendedGCD(int a, int b) {
	if (b == 0) {
		return {1, 0, a};
	}
	vector<int> v = extendedGCD(b, a % b);
	return {v[1], v[0] - (a / b)*v[1], v[2]};
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << gcd(18, 24) << "\n";
	vector<int> v = extendedGCD(18, 24);
	for (auto x : v) {
		cout << x << " ";
	}


}