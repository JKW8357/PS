#include <bits/stdc++.h>
using namespace std;

int n, m, blocks;
int height = 0, minTime = INT_MAX;
int ground[505][505];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> blocks;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> ground[i][j];

	// 높이를 h로 평탄하게 만들었을 때와 시간을 완전탐색으로 찾자! 0 <= h <= 256
	// 최악의 경우에도 충분히 탐색이 가능하므로 OK
	for (int curHeight = 0; curHeight <= 256; curHeight++) {
		int curBlocks = blocks;
		int curTime = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (ground[i][j] >= curHeight) {
					curTime += 2 * (ground[i][j] - curHeight);
					curBlocks += (ground[i][j] - curHeight);
				}

				else {
					curTime += (curHeight - ground[i][j]);
					curBlocks -= (curHeight - ground[i][j]);
				}
			}
		}

		if (curBlocks < 0) continue;
		if (minTime >= curTime) {
			minTime = curTime;
			height = curHeight;
		}
	}

	cout << minTime << ' ' << height << '\n';
	return 0;
}