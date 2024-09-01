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

	// map을 vector로 복사하지 않고 map을 순회하며 최댓값/최솟값 구하기
	for (auto it = um.begin(); it != um.end(); it++) {
		mintime = min(mintime, it->second);
		maxtime = max(maxtime, it->second);
	}

	cout << (maxtime - mintime <= 12 ? "Yes\n" : "No\n");
	return 0;
}