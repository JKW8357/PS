#include <bits/stdc++.h>
using namespace std;

bool vis[10005];
string ans[10005];

string bfs(int a, int b) {
	queue<int> q;
	q.push(a);
	vis[a] = true;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == b) return ans[cur];
		
		int nxtd = (cur * 2) % 10000;
		if (!vis[nxtd]) {
			q.push(nxtd);
			vis[nxtd] = true;
			ans[nxtd] = ans[cur] + "D";
		}

		int nxts = (cur + 9999) % 10000;
		if (!vis[nxts]) {
			q.push(nxts);
			vis[nxts] = true;
			ans[nxts] = ans[cur] + "S";
		}

		int nxtl = (cur * 10 + cur / 1000) % 10000;
		if (!vis[nxtl]) {
			q.push(nxtl);
			vis[nxtl] = true;
			ans[nxtl] = ans[cur] + "L";
		}

		int nxtr = cur / 10 + (cur % 10) * 1000;
		if (!vis[nxtr]) {
			q.push(nxtr);
			vis[nxtr] = true;
			ans[nxtr] = ans[cur] + "R";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int a, b;
		cin >> a >> b;
		fill(vis, vis + 10005, false);
		fill(ans, ans + 10005, "");
		cout << bfs(a, b) << '\n';
	}
	
	return 0;
}