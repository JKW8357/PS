#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = n; i >= 4; i--) {
		string str = to_string(i);
		if (str.find_first_not_of("47") != string::npos) continue;
		else {
			cout << i << '\n';
			return 0;
		}
	}
}