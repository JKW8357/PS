#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int cnt = 0;
	while (n != 0) {
		string tmp = to_string(n);
		auto idx = tmp.find("1");
		if (idx == string::npos) {
			cnt++;
			n--;
		}
		else {
			tmp.erase(idx, 1);
			cnt++;
			n = tmp.empty() ? 0 : stoi(tmp);
		}
	}

	cout << cnt;
	return 0;
}