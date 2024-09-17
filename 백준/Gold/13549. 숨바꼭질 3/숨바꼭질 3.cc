#include <bits/stdc++.h>
using namespace std;

const int MX = 100000;
int dis[100005];

// 0-1 bfs를 이용한 풀이
int zeroOneBfs(int n, int k) {
	deque<int> dq;
	dq.push_back(n);
	dis[n] = 0;

	while (!dq.empty()) {
		int cur = dq.front(); dq.pop_front();

		if (2 * cur <= MX && dis[2 * cur] == -1) {
			dis[2 * cur] = dis[cur];
			dq.push_front(2 * cur); // 가중치가 0이므로 deque의 앞에 추가
		}

		for (int nxt : {cur - 1, cur + 1}) {
			if (nxt < 0 || nxt > MX || dis[nxt] != -1) continue;
			dis[nxt] = dis[cur] + 1;
			dq.push_back(nxt); // 가중치가 1이므로 deque의 뒤에 추가
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
	cout << zeroOneBfs(n, k) << '\n';
	
	return 0;
}

/*
1. 일반 BFS: 가중치가 모두 1일 때만 사용 가능
시간 복잡도: O(V + E)

2. 데이크스트라 알고리즘: 가중치가 0 또는 양수인 경우에 사용 가능
시간 복잡도: O(E log V)

3. 0-1 BFS: 가중치가 0과 1인 경우에 가장 적합
시간 복잡도: O(V + E)
특징: 덱을 사용해 가중치 0인 경로를 먼저 처리하여 최단 경로를 효율적으로 탐색
*/