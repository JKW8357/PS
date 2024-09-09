#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string str;
	cin >> n >> str;

	int idx = 0, cnt = 0;
	while (true) {
		idx = str.find("pPAp", idx);
		if (idx == string::npos) break;
		idx += 4;
		cnt++;
	}

	cout << cnt << '\n';
	return 0;
}