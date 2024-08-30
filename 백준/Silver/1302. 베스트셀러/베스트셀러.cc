#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> p1, pair<string, int> p2) {
	if (p1.second != p2.second) return p1.second > p2.second;
	return p1.first < p2.first;
}

unordered_map<string, int> um;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while (n--) {
		string title;
		cin >> title;
		um[title]++;
	}

	vector<pair<string, int>> vec(um.begin(), um.end());
	sort(vec.begin(), vec.end(), cmp);
	cout << vec[0].first << '\n';

	return 0;
}