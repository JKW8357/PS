#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	int ans = 0;
	while (n--) {
		string str;
		cin >> str;
		if (str.find("01") != string::npos || str.find("OI") != string::npos) ans++;
	}

	cout << ans << '\n';
	return 0;
}