#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cout << "String #" << i << '\n';
		string name;
		cin >> name;
		for (char c : name) cout << char('A' + (c + 1 - 'A') % 26);
		cout << "\n\n";
	}
	
	return 0;
}