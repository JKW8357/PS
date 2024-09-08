#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string n;
	cin >> n;

	int cnt = 0;
	while (n.size() > 1) {
		int tmp = 0;
		int size = n.size();
		for (int i = 0; i < size; i++) {
			tmp += n[i] - '0';
		}
		n = to_string(tmp);
		cnt++;
	}

	cout << cnt << '\n' << (stoi(n) % 3 == 0 ? "YES\n" : "NO\n");
	return 0;
}