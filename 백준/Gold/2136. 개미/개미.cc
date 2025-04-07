#include <bits/stdc++.h>
using namespace std;

vector<int> pos;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, len;
	cin >> n >> len;
	pos.resize(n);
	for (int i = 0; i < n; i++) cin >> pos[i];
	auto sortedPos = pos;
	sort(sortedPos.begin(), sortedPos.end(), [](int a, int b) { return abs(a) < abs(b); });

	int leftmostIdx = 0, rightmostIdx = n - 1;
	int leftmostTime = 0, rightmostTime = 0;
	for (int i = 0; i < n; i++) {
		if (sortedPos[i] > 0) {
			leftmostIdx = i;
			leftmostTime = len - sortedPos[i];
			break;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		if (sortedPos[i] < 0) {
			rightmostIdx = i;
			rightmostTime = -sortedPos[i];
			break;
		}
	}

	int moveLeftCnt = 0, moveRightCnt = 0;
	for (int i = 0; i < n; i++) {
		if (pos[i] < 0) moveLeftCnt++;
		else moveRightCnt++;
	}
	
	if (leftmostTime > rightmostTime) {
		int id = find(pos.begin(), pos.end(), sortedPos[moveLeftCnt]) - pos.begin() + 1;
		cout << id << ' ' << leftmostTime << '\n';
	}
	else {
		int id = find(pos.begin(), pos.end(), sortedPos[n - moveRightCnt - 1]) - pos.begin() + 1;
		cout << id << ' ' << rightmostTime << '\n';
	}

	return 0;
}