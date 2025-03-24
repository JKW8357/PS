#include <bits/stdc++.h>
using namespace std;

bool candidates[1000];
vector<string> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// candidates, vec 전처리
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				if (i == j || i == k || j == k) continue;
				int num = 100 * i + 10 * j + k;
				candidates[num] = true;
				vec.push_back(to_string(num));
			}
		}
	}

	int n; cin >> n;
	while (n--) {
		string query;
		int strike, ball;
		cin >> query >> strike >> ball;

		// 매 쿼리마다 수들을 완전탐색으로 확인해도 문제 없다!
		for (auto& num : vec) {
			if (!candidates[stoi(num)]) continue;

			int strikeCount = 0;
			int ballCount = 0;

			for (int i = 0; i < 3; i++) {
				if (query[i] == num[i]) strikeCount++;
				else {
					for (int j = 0; j < 3; j++)
						if (i != j && query[i] == num[j]) ballCount++;
				}
			}

			if (strike != strikeCount || ball != ballCount) candidates[stoi(num)] = false;
		}
	}

	int ans = 0;
	for (int i = 123; i <= 987; i++)
		if (candidates[i]) ans++;
	cout << ans << '\n';

	return 0;
}