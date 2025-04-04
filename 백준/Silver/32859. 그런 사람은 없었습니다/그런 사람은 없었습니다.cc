#include <bits/stdc++.h>
using namespace std;

int submitTime[2005];
int depositTime[2005];
int prefix[4005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, s;
	cin >> n >> m >> s;
	fill(submitTime + 1, submitTime + n + 1, INT_MAX);
	fill(depositTime + 1, depositTime + n + 1, -1);
	
	for (int t = 1; t <= m; t++) {
		int i, deposit;
		cin >> i >> deposit;
		
		prefix[t] = prefix[t - 1];
		if (deposit) depositTime[i] = t;
		else {
			submitTime[i] = t;
			prefix[t]++;
		}
	}

	vector<int> ans;
	bool found = false;
	for (int i = 1; i <= n; i++) {
		if (depositTime[i] == -1) continue;
		if (prefix[min(m, submitTime[i] - 1)] - prefix[depositTime[i]] >= s) {
			ans.push_back(i);
			found = true;
		}
	}

	if (ans.empty()) cout << -1 << '\n';
	else for (int x : ans) cout << x << '\n';
	return 0;
}