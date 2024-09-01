#include <bits/stdc++.h>
using namespace std;

int worktime[4] = { 4, 6, 4, 10 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int weeks;
	cin >> weeks;

	unordered_map<string, int> um;
	for (int i = 0; i < weeks; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 7; k++) {
				string name;
				cin >> name;
				if (name == "-") continue;
				else um[name] += worktime[j];
			}
		}
	}

	int mintime = INT_MAX;
	int maxtime = INT_MIN;

	// unordered_map을 vector로 복사하지 않고 직접 순회하며 최댓값과 최솟값을 구함
	// 이를 통해 불필요한 메모리 사용과 복사 시간을 줄일 수 있음
	for (auto it = um.begin(); it != um.end(); it++) {
		mintime = min(mintime, it->second);
		maxtime = max(maxtime, it->second);
	}

	cout << (maxtime - mintime <= 12 ? "Yes\n" : "No\n");
	return 0;
}
