#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int maxSongCount = 0;
int minGuitarCount = INT_MAX;
string name, playlist;
ll guitars[10];

int popCountll(ll num) {
	int count = 0;
	while (num) {
		num &= (num - 1);
		count++;
	}
	return count;
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

	for (int mask = 0; mask < (1 << n); mask++) {
		ll state = 0;

		for (int i = 0; i < n; i++)
			if (mask & (1 << i))
				state |= guitars[i];

		int songs = popCountll(state);
		int guitarCount = popCountll(mask);

		if (maxSongCount <= songs) {
            minGuitarCount = (maxSongCount == songs ? min(minGuitarCount, guitarCount) : guitarCount);
			maxSongCount = songs;
		}
	}

	cout << (maxSongCount > 0 ? minGuitarCount : -1) << '\n';
	return 0;
}
