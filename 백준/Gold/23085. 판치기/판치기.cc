#include <bits/stdc++.h>
using namespace std;

int n, k;
bool vis[3005];

int bfs(int st) {
	queue<pair<int, int>> q;
	q.push({ st, 0 });
	vis[st] = true;

	while (!q.empty()) {
		auto [heads, cnt] = q.front(); q.pop();
		int tails = n - heads;
		if (tails == n) return cnt;
		for (int i = 0; i <= k; i++) {
			int reversedHeads = i;
			int reversedTails = k - i;
			int nxt = heads - reversedHeads + reversedTails;
			if (reversedHeads > heads || reversedTails > tails || vis[nxt]) continue;
			q.push({ nxt, cnt + 1 });
			vis[nxt] = true;
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	string str; cin >> str;
    
	int heads = 0;
	for (char ch : str)
		if (ch == 'H') heads++;
	
	int ans = bfs(heads);
	cout << ans << '\n';

	return 0;
}