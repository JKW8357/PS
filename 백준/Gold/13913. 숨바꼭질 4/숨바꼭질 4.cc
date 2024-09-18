#include <bits/stdc++.h>
using namespace std;

const int MX = 100000;
int dis[100005];
int p[100005];
vector<int> track;

int bfs(int n, int k) {
	queue<int> q;
	q.push(n);
	dis[n] = 0;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : {cur - 1, cur + 1, cur * 2}) {
			if (nxt < 0 || nxt > MX || dis[nxt] != -1) continue;
			dis[nxt] = dis[cur] + 1;
			p[nxt] = cur;
			q.push(nxt);
		}
	}

	return dis[k];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	fill(dis, dis + MX + 1, -1);
	fill(p, p + MX + 1, -1);

	int ans = bfs(n, k);
	cout << ans << '\n';

	int cur = k;
	while (cur != -1) {
		track.push_back(cur);
		cur = p[cur];
	}
	
	reverse(track.begin(), track.end());
	for (int v : track) cout << v << ' ';
	return 0;
}