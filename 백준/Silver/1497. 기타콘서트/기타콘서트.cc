#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int maxSongCount = 0;
int minGuitarCount = INT_MAX;
string name, playlist;
ll guitars[10];

int popCountll(ll num) {
	int res = 0;
	for (int i = 0; i < m; i++) res += (num >> i) & 1;
	return res;
}

void solve(ll state, int guitarCount, int depth) {
	if (depth == n) {
		int songs = popCountll(state);
		if (songs >= maxSongCount) {
			maxSongCount = songs;
			minGuitarCount = min(minGuitarCount, guitarCount);
		}
		return;
	}

	solve(state | guitars[depth], guitarCount + 1, depth + 1);
	solve(state, guitarCount, depth + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> name >> playlist;
		for (int j = 0; j < m; j++)
			if (playlist[j] == 'Y') guitars[i] |= (1LL << j);
	}

	solve(0, 0, 0);
	cout << (minGuitarCount != 0 ? minGuitarCount : -1) << '\n';
	return 0;
}