#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cnt = 0;
	while (++cnt) {
		int n;
		cin >> n;
		if (n == 0) break;

		string name[25];
		vector<int> badMessages[25];

		cout << "Group " << cnt << '\n';
		for (int i = 0; i < n; i++) {
			cin >> name[i];
			for (int j = 0; j < n - 1; j++) {
				char message;
				cin >> message;
				if (message == 'N') badMessages[i].push_back(j);
			}
		}
		
		bool noNasty = true;
		for (int i = 0; i < n; i++) {
			if (!badMessages[i].empty()) {
				int size = badMessages[i].size();
				for (int nastys : badMessages[i]) {
					int nastyNum = (n + i - (nastys + 1)) % n;
					cout << name[nastyNum] << " was nasty about " << name[i] << '\n';
				}
				noNasty = false;
			}
		}

		if (noNasty) cout << "Nobody was nasty\n";
		cout << '\n';
	}

	return 0;
}