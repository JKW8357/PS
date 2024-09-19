#include <bits/stdc++.h>
using namespace std;

int cnt;
int choose[100005];
int state[100005];  // 상태 배열 (0: 방문하지 않음, 1: 방문함, 2: 탐색 완료)

void dfs(int cur) {
	state[cur] = 1;
	int nxt = choose[cur];

	if (state[nxt] == 0) dfs(nxt); // 방문하지 않은 node에 대해 dfs
	
	// 재방문한 node에 대해 cycle 탐지
	else if (state[nxt] == 1) {
		for (int i = nxt; i != cur; i = choose[i]) cnt++; // cycle에 포함된 학생들 count
		cnt++; // cur도 cycle에 포함
	}

	state[cur] = 2; // cur 탐색 완료
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
			state[i] = 0;
		}

		for (int i = 1; i <= n; i++) if (state[i] == 0) dfs(i); // 방문하지 않은 node에서만 dfs
		cout << n - cnt << '\n';
	}

	return 0;
}