#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<char, int> p1, pair<char, int> p2) {
	if (p1.second != p2.second) return p1.second > p2.second;
	return p1.first < p2.first;
}

string dna[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> dna[i];

	string ans;
	int hamming = 0;
	for (int j = 0; j < m; j++) {
		map <char, int> ACGT;
		for (int i = 0; i < n; i++) ACGT[dna[i][j]]++;

		vector<pair<char, int>> vec(ACGT.begin(), ACGT.end());
		sort(vec.begin(), vec.end(), cmp);

		ans += vec[0].first;
		hamming += n - vec[0].second;
	}

	cout << ans << '\n' << hamming << '\n';
	return 0;
}