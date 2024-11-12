#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	int ans = 0, tmp = 0;
	int size = str.size();
	bool isminus = false;

	for (int i = 0; i <= size; ++i) {
		if (i == size || str[i] == '+' || str[i] == '-') {

			int num = stoi(str.substr(tmp, i - tmp));

			if (isminus) ans -= num;
			else ans += num;

			tmp = i + 1;
			if (str[i] == '-') isminus = true;
		}
	}

	cout << ans;
	return 0;
}