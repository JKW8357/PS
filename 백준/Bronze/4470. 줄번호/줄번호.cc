#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++) {
		string str; getline(cin, str);
		cout << i << ". " << str << '\n';
	}

	return 0;
}