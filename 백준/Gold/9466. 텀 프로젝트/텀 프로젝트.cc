#include <bits/stdc++.h>
using namespace std;

int cnt;
int choose[100005];
bool vis[100005]; // 방문 여부 기록
bool finished[100005]; // dfs 완료 여부 기록

void dfs(int cur) {
	vis[cur] = true;
	int nxt = choose[cur];

	if (!vis[nxt]) dfs(nxt); // 방문하지 않은 node에 대해 dfs
	
	// 재방문한 node에 대해 cycle 탐지
	else if (!finished[nxt]) {
		for (int i = nxt; i != cur; i = choose[i]) cnt++; // cycle에 포함된 학생들 count
		cnt++; // cur도 cycle에 포함
	}

	finished[cur] = true; // cur 탐색 완료
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		cnt = 0;
		for (int i = 1; i <= n; i++) {
			cin >> choose[i];
			vis[i] = false;
			finished[i] = false;
		}

		for (int i = 1; i <= n; i++) dfs(i);
		cout << n - cnt << '\n';
	}

	return 0;
}