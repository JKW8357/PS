#include <bits/stdc++.h>
using namespace std;

vector<string> channels;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	channels.resize(n);
	for (int i = 0; i < n; i++) cin >> channels[i];
	int k1 = find(channels.begin(), channels.end(), "KBS1") - channels.begin();
	int k2 = find(channels.begin(), channels.end(), "KBS2") - channels.begin();
	for (int i = 0; i < k1; i++) cout << 1;
	for (int i = 0; i < k1; i++) cout << 4;
	for (int i = 0; i < (k1 > k2 ? k2 + 1 : k2); i++) cout << 1;
	for (int i = 0; i < (k1 < k2 ? k2 - 1 : k2); i++) cout << 4;

	return 0;
}