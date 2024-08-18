#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	string str;
	cin >> n >> str;

	int cnt = 0;
	bool flag = false;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'L') {
			i++;
			flag = true;
		}
		cnt++;
	}

	cout << (flag ? cnt + 1 : cnt);
	return 0;
}