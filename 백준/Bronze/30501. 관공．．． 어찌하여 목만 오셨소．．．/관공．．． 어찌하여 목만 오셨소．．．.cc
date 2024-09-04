#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	while (n--) {
		string name;
		cin >> name;
		if (name.find('S') != string::npos) cout << name << '\n';
	}

	return 0;
}