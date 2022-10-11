vector<int> rabinkarp(string &s , string &t) {
	int n = s.length() , m = t.length();
	const int p = 31;
	const int mod = 1e9 + 7;
	vector<int> pow_p(max(n, m));

	// calculating power at each length --  s string , t pattern
	pow_p[0] = 1;
	for (int i = 1 ; i < max(n, m) ; i++)
		pow_p[i] = (pow_p[i - 1] * p) % mod;

	// calculating hashing of text string
	vector<int> h(n + 1, 0);
	for (int i = 0 ; i < n ; i++)
		h[i + 1] = (h[i] + (s[i] - 'a' + 1) * pow_p[i]) % mod;

	int h_s = 0;
	for (int i = 0 ; i < m; i++)
		h_s = (h_s + (t[i] - 'a' + 1) * pow_p[i]) % mod;

	vector<int> occurences;
	for (int i = 0 ; i + m - 1 < n ; i++) {
		int cur_h = (h[i + m] + mod - h[i]) % mod;
		if (cur_h == h_s * pow_p[i] % mod)
			occurences.push_back(i);

	}
	return occurences;
}
