#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans = 0;
int missions[2][3];

void solve(int day, int score, int pre) {
	if (day == n) {
		if (score >= m) ans++;
		return;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			if (pre == j) solve(day + 1, score + missions[i][j] / 2, j);
			else solve(day + 1, score + missions[i][j], j);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			cin >> missions[i][j];

	solve(0, 0, -1);
	cout << ans << '\n';

	return 0;
}

/*
전체 경우의 수 6^8, 완전 탐색 가능!
재귀함수를 사용하는 이유:
문제의 구조를 보면, 이전 상태(이전에 방문한 장소)를 기억해야 함
단순 for문을 사용하기보다 재귀함수를 사용하면 보다 효과적으로 상태를 기억할 수 있다. 
*/